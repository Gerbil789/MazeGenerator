#ifndef MAZE_SOLVER_STRATEGY
#define MAZE_SOLVER_STRATEGY

#include <stack>
#include <optional>
#include <functional>
#include <memory>
#include "maze.h"

class MazeSolverStrategy{
protected:
    void callCallback(const Maze& maze, std::function<void(const Maze&)> callback){
        if(callback != nullptr){
            callback(maze);
        }
    }
public:
    virtual void solveMaze(Maze& maze, std::function<void(const Maze&)> callback = 0) = 0;
};
#endif