#include "mazeSolverStrategy.h"

class DeadEndFillingStrategy : public MazeSolverStrategy
{
private:
    bool fillDeadEnds(Maze& maze);
public:
    void solveMaze(Maze& maze, std::function<void(const Maze&)> callback) override;
    
};

