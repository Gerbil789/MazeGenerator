#include "mazeGeneratorStrategy.h"
#include "mazeSolverStrategy.h"

class MazeGenerator{
private:
    std::shared_ptr<MazeGeneratorStrategy> generator_strategy;
    std::shared_ptr<MazeSolverStrategy> solver_strategy;
public:
    MazeGenerator(std::shared_ptr<MazeGeneratorStrategy> g_strategy, std::shared_ptr<MazeSolverStrategy> s_strategy);
    void GenerateMaze(Maze& maze, std::function<void(const Maze&)> callback = nullptr);
    void SolveMaze(Maze& maze, std::function<void(const Maze&)> callback = nullptr);
};