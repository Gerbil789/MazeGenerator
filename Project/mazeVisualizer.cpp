#include "mazeVisualizer.h"

void MazeVisualizer::Vizualize(const Maze& maze, sf::RenderWindow& window, Color defaultColor, Color visitedColor)
{
    window.clear(sf::Color(defaultColor.r,defaultColor.g,defaultColor.b,255));
    for(int x = 0; x < maze.width; x++){
        for(int y = 0; y < maze.height; y++){
            const Cell& cell = maze.cells[x][y];

            //cell
            if(cell.visited){
               sf::RectangleShape rect(sf::Vector2f(40, 40));
               rect.setPosition(x * 40, y * 40);
               rect.setFillColor(sf::Color(visitedColor.r, visitedColor.g, visitedColor.b, 255));
               window.draw(rect);
            }

            //walls
            if(cell.up){
               sf::RectangleShape wall(sf::Vector2f(40, 4));
               wall.setPosition(x * 40, y * 40 - 2);
               window.draw(wall);
            }

            if(cell.down){
               sf::RectangleShape wall(sf::Vector2f(40, 4));
               wall.setPosition(x * 40, (y + 1) * 40 - 4 + 2);
               window.draw(wall);
            }

            if(cell.left){
               sf::RectangleShape wall(sf::Vector2f(4, 40));
               wall.setPosition(x * 40 - 2, y * 40);
               window.draw(wall);
            }

            if(cell.right){
               sf::RectangleShape wall(sf::Vector2f(4, 40));
               wall.setPosition((x + 1) * 40 - 4 + 2, y * 40);
               window.draw(wall);
            }
        }
    }
    window.display();
}