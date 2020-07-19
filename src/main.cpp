/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** main
*/

#include "Board.hpp"
#include "Game.hpp"

int main(int ac, char **av)
{
    try {
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), NAME);
        Game g(&window, ac > 1 ? av[1] : DEFAULT_MAP);
        g.run();
    } catch (const Error &e) {
        e.printErr();
    }
    return 0;
}
