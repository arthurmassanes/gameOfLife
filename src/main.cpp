/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** main
*/

#include "Board.hpp"
#include "Game.hpp"

int main(void)
{
    try {
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), NAME);
        Game g(&window);
        g.run();
    } catch (const Error &e) {
        e.printErr();
    }
    return 0;
}
