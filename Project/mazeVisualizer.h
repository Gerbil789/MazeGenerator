#include <SFML/Graphics.hpp>
#include "maze.h"

class MazeVisualizer{
public:
    static void Vizualize(const Maze& maze, sf::RenderWindow& window, Color defaultColor, Color visitedColor);
};