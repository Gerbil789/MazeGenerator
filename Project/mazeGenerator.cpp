#include "mazeGenerator.h"

MazeGenerator::MazeGenerator(std::shared_ptr<MazeGeneratorStrategy> g_strategy,std::shared_ptr<MazeSolverStrategy> s_strategy)
 : generator_strategy(g_strategy), solver_strategy(s_strategy) {}


void MazeGenerator::GenerateMaze(Maze& maze, std::function<void(const Maze&)> callback)
{   
    generator_strategy->generateMaze(maze, callback);
}

void MazeGenerator::SolveMaze(Maze& maze, std::function<void(const Maze&)> callback)
{
    solver_strategy->solveMaze(maze, callback);
}
