/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** main
*/

#include "Board.hpp"
#include "Game.hpp"

int printHelp(void)
{
    std::cout << "\tgameOfLife" << "\n";
    std::cout << "USAGE\n./gameOflife [-h] [MAP_FILE]";
    std::cout << "\n\n\tMAP_FILE\tThe file containing cells\n";
    std::cout << "\t-h\t\tDisplay usage" << "\n";
    return (0);
}

bool isHelpOption(int ac, char **av)
{
    return (ac > 1 && std::string(av[1]) == "-h");
}

int main(int ac, char **av)
{
    if (isHelpOption(ac, av))
        return (printHelp());
    try {
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), NAME);
        Game g(&window, ac > 1 ? av[1] : DEFAULT_MAP);
        g.run();
    } catch (const Error &e) {
        e.printErr();
    }
    return 0;
}
