#include "depthFirstSearchGeneratingStrategy.h"

void DepthFirstSearchGeneratingStrategy::generateMaze(Maze& maze, std::function<void(const Maze&)> callback){
    //this->maze = maze;
    is_generated = false;
    position = {0,0};
    current = &maze.cells[position.x][position.y];
    current->visited = true;
    path.push(position);

    while (is_generated == false)
    {
        auto newPosition = ChooseNextCell(maze);
        if(newPosition)
        {
            Cell* next = &maze.cells[newPosition->x][newPosition->y];
            next->visited = true;

            //remove walls
            if (position.x > newPosition->x)
            {
                current->left = false;
                next->right = false;
            }
            if (position.x < newPosition->x)
            {
                current->right = false;
                next->left = false;
            }
            if (position.y > newPosition->y)
            {
                current->up = false;
                next->down = false;
            }
            if (position.y < newPosition->y)
            {
                current->down = false;
                next->up = false;
            }

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
        }else{
            is_generated = true;
        }
        callCallback(maze, callback);
    }
    
}


std::optional<Vector2> DepthFirstSearchGeneratingStrategy::ChooseNextCell(Maze& maze)
{
    std::vector<Vector2> next_cell_list;
    // Check left
    if (position.x - 1 >= 0)
    {
        if (!maze.cells[position.x - 1][position.y].visited)
        {
            next_cell_list.push_back({position.x - 1, position.y});
        }
    }
    // Check right
    if (position.x + 1 < maze.width)
    {
        if (!maze.cells[position.x + 1][position.y].visited)
        {
            next_cell_list.push_back({position.x + 1, position.y});
        }
    }
    // Check top
    if (position.y - 1 >= 0)
    {
        if (!maze.cells[position.x][position.y - 1].visited)
        {
            next_cell_list.push_back({position.x, position.y - 1});
        }
    }
    // Check bottom
    if (position.y + 1 < maze.height)
    {
        if (!maze.cells[position.x][position.y + 1].visited)
        {
            next_cell_list.push_back({position.x, position.y + 1});
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
