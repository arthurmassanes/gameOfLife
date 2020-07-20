/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** toolbar
*/

#ifndef TOOLBAR_HPP_
#define TOOLBAR_HPP_

#include "Board.hpp"
#define FONT "fonts/font.ttf"
#define KEYS_TEXT "[Left] Move left\n[Right] Move right\
\n[Up] Zoom in\
\n[Down] Zoom out\
\n[Space] Toggle pause"

#define CELLS_TEXT "Cells: "
#define GENERATION_TEXT "Generation: "

class Toolbar
{
    sf::RectangleShape _bar;
    sf::Color _barColor;
    sf::Font _font;
    sf::Text _generation;
    sf::Text _keysList;
    sf::Text _cells;
    sf::Text _fileNameText;
    int _generationNb;
    std::string _fileName;
public:
    Toolbar(void);
    Toolbar(sf::Color);
    Toolbar(sf::Color, std::string);
    void draw(sf::RenderWindow *);
    void update(int generation, int cells = 0);
    void loadInstructions(void);

};


#endif
