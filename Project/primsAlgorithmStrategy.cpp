#include "primsAlgorithmStrategy.h"

void PrimsAlgrorithmStrategy::generateMaze(Maze& maze, std::function<void(const Maze&)> callback){
    position = {0,0};
    maze.cells[position.x][position.y].visited = true;
    GetWalls(maze);

    while(!walls.empty()){
        int i = rand() % walls.size();
        Wall wall = walls[i];
        Cell* c1 = &maze.cells[wall.c1.x][wall.c1.y];
        Cell* c2 = &maze.cells[wall.c2.x][wall.c2.y];

        if(c1->visited ^ c2->visited){
        
            c2->visited = true;

            if(c1->x > c2->x){
                c1->left = false;
                c2->right = false;
            }else if(c1->x < c2->x){
                c1->right = false;
                c2->left = false;
            }else if(c1->y > c2->y){
                c1->up = false;
                c2->down = false;
            }else if(c1->y < c2->y){
                c1->down = false;
                c2->up = false;
            }
            position = {c2->x, c2->y};
            GetWalls(maze);
        }

        walls.erase(walls.begin() + i);
        callCallback(maze, callback);
    }
}

void PrimsAlgrorithmStrategy::GetWalls(Maze& maze){
    // Check left
    if (position.x - 1 >= 0){
        if (!maze.cells[position.x - 1][position.y].visited){
            walls.push_back({position, {position.x - 1, position.y}});
        }
    }
    // Check right
    if (position.x + 1 < maze.width){
        if (!maze.cells[position.x + 1][position.y].visited){
            walls.push_back({position, {position.x + 1, position.y}});
        }
    }
    // Check top
    if (position.y - 1 >= 0){
        if (!maze.cells[position.x][position.y - 1].visited){
            walls.push_back({position, {position.x, position.y - 1}});
        }
    }
    // Check bottom
    if (position.y + 1 < maze.height){
        if (!maze.cells[position.x][position.y + 1].visited){
            walls.push_back({position, {position.x, position.y + 1}});
        }
    }
}