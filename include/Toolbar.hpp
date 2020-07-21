/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** toolbar
*/

#ifndef TOOLBAR_HPP_
#define TOOLBAR_HPP_

#include "Board.hpp"
#include "HelpButton.hpp"
#define FONT "fonts/font.ttf"

#define CELLS_TEXT "Cells: "
#define GENERATION_TEXT "Generation: "
#define PAUSE_TEXT "[Space] Launch simulation"

class Toolbar
{
    sf::RenderWindow *_win;
    sf::RectangleShape _bar;
    sf::Color _barColor;
    sf::Font _font;
    sf::Text _generation;
    sf::Text _cells;
    sf::Text _fileNameText;
    sf::Text _pause;
    int _generationNb;
    std::string _fileName;
    HelpButton *_helpButton;
public:
    Toolbar(void);
    Toolbar(sf::Color);
    Toolbar(sf::Color, std::string);
    ~Toolbar(void);
    void draw(sf::RenderWindow *, bool);
    void update(int generation, int cells = 0);
    void loadInstructions(void);

};


#endif
