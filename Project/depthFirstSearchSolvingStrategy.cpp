#include "depthFirstSearchSolvingStrategy.h"
#include <iostream>

void DepthFirstSearchSolvingStrategy::solveMaze(Maze& maze, std::function<void(const Maze&)> callback){
    for(int i = 0; i < maze.width; i++){
        for(int j = 0; j < maze.height; j++){
            maze.cells[i][j].visited = false;
        }
    }
    Vector2 goal = {maze.width - 1,maze.height - 1};
    position = {0,0};
    current = &maze.cells[position.x][position.y];
    current->visited = true;
    path.push(position);

    while (position.x != goal.x || position.y != goal.y)
    {
        auto newPosition = ChooseNextCell(maze);
        if(newPosition)
        {
            Cell* next = &maze.cells[newPosition->x][newPosition->y];
            next->visited = true;

            
            // Set next cell as the current
            position = *newPosition;
            current = next;
            path.push(position);
        }else if(!path.empty()){
            auto newPosition = path.top();
            position.x = newPosition.x;
            position.y = newPosition.y;
            current = &maze.cells[position.x][position.y];
            path.pop();
        }
        callCallback(maze, callback);
    }

    for(int i = 0; i < maze.width; i++){
        for(int j = 0; j < maze.height; j++){
            maze.cells[i][j].visited = true;
        }
    }
    while(path.empty() == false){
        Vector2 pos = path.top();
        path.pop();
        maze.cells[pos.x][pos.y].visited = false;
        //std::cout << "[ "<< pos.x << " " << pos.y << " ]\n";
    }
    //callCallback(maze, callback);
    
}


std::optional<Vector2> DepthFirstSearchSolvingStrategy::ChooseNextCell(Maze& maze)
{
    std::vector<Vector2> next_cell_list;
    // Check left
    if (position.x - 1 >= 0)
    {
        if(!current->left){
            if (!maze.cells[position.x - 1][position.y].visited)
            {
                next_cell_list.push_back({position.x - 1, position.y});
            }
        }
        
    }
    // Check right
    if (position.x + 1 < maze.width)
    {
        if(!current->right){
            if (!maze.cells[position.x + 1][position.y].visited)
            {
                next_cell_list.push_back({position.x + 1, position.y});
            }
        }
        
    }
    // Check up
    if (position.y - 1 >= 0)
    {
        if(!current->up){
            if (!maze.cells[position.x][position.y - 1].visited)
            {
                next_cell_list.push_back({position.x, position.y - 1});
            }
        }
        
    }
    // Check down
    if (position.y + 1 < maze.height)
    {
        if(!current->down){
            if (!maze.cells[position.x][position.y + 1].visited)
            {
                next_cell_list.push_back({position.x, position.y + 1});
            }
        }
    }
    // Selected next cell
    if (next_cell_list.size() > 0)
    {
        int index = std::rand() % next_cell_list.size();
        return next_cell_list[index];
    }
    return std::nullopt;
}
