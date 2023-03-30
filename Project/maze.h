#ifndef MAZE
#define MAZE

#include <vector>
#include <cstdint>

struct Color
{
    Color(uint8_t r, uint64_t g, uint8_t b) : r(r), g(g), b(b) {}
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Vector2
{
    Vector2(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

class Cell
{
public:
    Cell(int x, int y);
    void SetPosition(int x, int y);

    int x;
    int y;
    bool up;
    bool down;
    bool left;
    bool right;
    bool visited;
};

class Maze
{
public:
    Maze(int width, int height);
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
};

#endif
