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
    sf::RenderWindow window(sf::VideoMode(1000, 1000), NAME);

    try {
        Game g(&window);
        g.run();
    } catch (const Error &e) {
        e.printErr();
    }
    return 0;
}
