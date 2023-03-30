#include "maze.h"

Cell::Cell(int x, int y) : x(x), y(y)
{
    up = true;
    down = true;
    left = true;
    right = true;

    visited = false;
}

void Cell::SetPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

Maze::Maze(int width, int height) : width(width), height(height), cells(width, std::vector<Cell>(height, Cell(0, 0)))
{
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            cells[x][y].SetPosition(x, y);
        }
    }
}
