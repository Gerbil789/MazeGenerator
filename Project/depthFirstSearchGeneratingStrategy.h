#include "mazeGeneratorStrategy.h"

class DepthFirstSearchGeneratingStrategy : public MazeGeneratorStrategy{
private:
    Vector2 position = {0,0};
    bool is_generated = false;
    Cell* current = nullptr;
    std::stack<Vector2> path;

    std::optional<Vector2> ChooseNextCell(Maze& maze);
public:
    void generateMaze(Maze& maze, std::function<void(const Maze&)> callback) override;
    
};

