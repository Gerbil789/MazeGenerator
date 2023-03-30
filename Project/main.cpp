#include "mazeGenerator.h"
#include "depthFirstSearchGeneratingStrategy.h"
#include "primsAlgorithmStrategy.h"
#include "mazeVisualizer.h"
#include "deadEndFillingStrategy.h"
#include "depthFirstSearchSolvingStrategy.h"
#include <memory>

#include <iostream>

std::shared_ptr<MazeGeneratorStrategy> GetGenerateStrategy(int index, int &delay)
{
    switch (index){
    case 0:
        delay = 5;
        return std::shared_ptr<MazeGeneratorStrategy>(new DepthFirstSearchGeneratingStrategy);
    case 1:
        delay = 5;
        return std::shared_ptr<MazeGeneratorStrategy>(new PrimsAlgrorithmStrategy);
    default:
        return nullptr;
    }
}

std::shared_ptr<MazeSolverStrategy> GetSolverStrategy(int index, int &delay)
{
    switch (index){
    case 0:
        delay = 5;
        return std::shared_ptr<MazeSolverStrategy>(new DepthFirstSearchSolvingStrategy);
    case 1:
        delay = 100;
        return std::shared_ptr<MazeSolverStrategy>(new DeadEndFillingStrategy);
    default:
        return nullptr;
    }
}

void ReadArguments(int argc, char **argv, int &generateDelay, int &solveDelay, int &width, int &height,
            std::shared_ptr<MazeGeneratorStrategy> &g_strategy, std::shared_ptr<MazeSolverStrategy> &s_strategy)
{
    if (argc >= 2){
        g_strategy = GetGenerateStrategy(std::atoi(argv[1]), generateDelay);
    }
    if (argc >= 3){
        s_strategy = GetSolverStrategy(std::atoi(argv[2]), solveDelay);
    }
    if (argc >= 4){
        width = std::atoi(argv[3]);
    }
    if (argc >= 5){
        height = std::atoi(argv[4]);
    }
}

int main(int argc, char **argv)
{
    std::shared_ptr<MazeGeneratorStrategy> g_strategy(new DepthFirstSearchGeneratingStrategy);
    std::shared_ptr<MazeSolverStrategy> s_strategy(new DeadEndFillingStrategy);
    int generateDelay = 5; // miliseconds
    int solveDelay = 100;  // miliseconds
    int width = 16;
    int height = 16;

    ReadArguments(argc, argv, generateDelay, solveDelay, width, height, g_strategy, s_strategy);

    std::srand(std::time(nullptr));
    sf::RenderWindow window(sf::VideoMode(width * 40, height * 40), "Maze Generator");
    Maze maze(width, height);
    MazeGenerator generator(g_strategy, s_strategy);

    generator.GenerateMaze(maze, [&](const Maze &maze)
                           {
                               MazeVisualizer::Vizualize(maze, window, {150, 150, 150}, {50, 50, 50});
                               sf::sleep(sf::milliseconds(generateDelay));
                           });

    generator.SolveMaze(maze, [&](const Maze &maze)
                        {
                            MazeVisualizer::Vizualize(maze, window, {50,50,50}, {255,70,0});
                            sf::sleep(sf::milliseconds(solveDelay)); 
                        });


    //highlight path with different color
    MazeVisualizer::Vizualize(maze, window, {0, 200, 0}, {50, 50, 50});


    //loop to keep window open
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);
    }

    return 0;
}

// optimalizations to do:

// algorithm strategies store reference to maze, so it does not have to pass over and over