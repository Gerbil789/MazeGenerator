#ifndef MAZE_GENERATOR_STRATEGY
#define MAZE_GENERATOR_STRATEGY

#include <stack>
#include <optional>
#include <functional>
#include <memory>
#include "maze.h"

class MazeGeneratorStrategy{
protected:
    void callCallback(const Maze& maze, std::function<void(const Maze&)> callback){
        if(callback != nullptr){
            callback(maze);
        }
    }
public:
    virtual void generateMaze(Maze& maze, std::function<void(const Maze&)> callback = 0) = 0;
};
#endif