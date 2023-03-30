#include "deadEndFillingStrategy.h"

void DeadEndFillingStrategy::solveMaze(Maze& maze, std::function<void(const Maze&)> callback)
{
    for(int i = 0; i < maze.width; i++){
        for(int j = 0; j < maze.height; j++){
            maze.cells[i][j].visited = false;
        }
    }

    while(fillDeadEnds(maze) == false){
        callCallback(maze, callback);
    }
}

bool DeadEndFillingStrategy::fillDeadEnds(Maze& maze){
    bool solved = true;
    for(int i = 0; i < maze.width; i++){
        for(int j = 0; j < maze.height; j++){
            if((i == 0 && j == 0) || (i == maze.width - 1 && j == maze.height - 1)){
                continue;
            }

            if(!maze.cells[i][j].visited){
                int count = 0;
                if(maze.cells[i][j].up || maze.cells[i][j - 1].visited){count++;}
                if(maze.cells[i][j].down || maze.cells[i][j + 1].visited){count++;}
                if(maze.cells[i][j].left || maze.cells[i - 1][j].visited){count++;}
                if(maze.cells[i][j].right || maze.cells[i + 1][j].visited){count++;}

                if(count >= 3){
                    maze.cells[i][j].visited = true;
                    solved = false;
                }
            }
        }
    }
    return solved;
}