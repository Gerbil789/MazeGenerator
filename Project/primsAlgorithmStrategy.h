#include "mazeGeneratorStrategy.h"

class PrimsAlgrorithmStrategy : public MazeGeneratorStrategy{
private:
    Vector2 position = {0,0};

    struct Wall{
        Vector2 c1;
        Vector2 c2;
    };

    std::vector<Wall> walls;
    void GetWalls(Maze& maze);
public:
    void generateMaze(Maze& maze, std::function<void(const Maze&)> callback) override;
    
};

