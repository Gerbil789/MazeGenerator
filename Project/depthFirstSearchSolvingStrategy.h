#include "mazeSolverStrategy.h"

class DepthFirstSearchSolvingStrategy : public MazeSolverStrategy{
private:
    Vector2 position = {0,0};
    bool is_solved = false;
    Cell* current = nullptr;
    std::stack<Vector2> path;

    std::optional<Vector2> ChooseNextCell(Maze& maze);
public:
    void solveMaze(Maze& maze, std::function<void(const Maze&)> callback) override;
    
};

