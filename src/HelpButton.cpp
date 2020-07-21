/*
** ARTHUR MASSANES PROJECT, 2020
** gameOfLife
** File description:
** help button
*/

#include "HelpButton.hpp"

HelpButton::HelpButton(sf::Font &font): _font(font)
{
    _buttonWidth = 125;
    _buttonHeight = 30;
    _popupWidth = 500;
    _popupHeight = 300;

    _keysList = sf::Text(KEYS_TEXT, _font);
    _keysList.setFillColor(sf::Color(0, 0, 0, 150));
    _keysList.setCharacterSize(22);
    _background.setFillColor(sf::Color(0, 0, 0, 200));
    _background.setSize(sf::Vector2f(_buttonWidth, _buttonHeight));
    _background.setPosition(sf::Vector2f(0, 0));
    _background.setOutlineThickness(5);
    _background.setOutlineColor(sf::Color(0, 0, 0, 100));

    _popup.setFillColor(sf::Color(236, 240, 241, 250));
    _popup.setSize(sf::Vector2f(_popupWidth, _popupHeight));
    _popup.setPosition(sf::Vector2f(0, 0));
    _popup.setOutlineThickness(5);
    _popup.setOutlineColor(sf::Color::Black);

    _helpText = sf::Text(HELP_TEXT, _font);
    _helpText.setFillColor(sf::Color::White);
    _helpText.setCharacterSize(20);
    _helpText.setPosition(sf::Vector2f(_background.getPosition().x + X_OFFSET, _background.getPosition().y + Y_OFFSET ));
}

void HelpButton::setPosition(sf::Vector2f pos)
{
    _background.setPosition(pos);
    _helpText.setPosition(sf::Vector2f(_background.getPosition().x + X_OFFSET, _background.getPosition().y + Y_OFFSET));
}

void HelpButton::update(sf::RenderWindow *win)
{
    auto mousePos = (sf::Vector2<float>)sf::Mouse::getPosition(*win);
    auto bgPos = _background.getPosition();

    if ((mousePos.x >= bgPos.x && mousePos.x <= bgPos.x + _buttonWidth)
        && (mousePos.y >= bgPos.y && mousePos.y <= bgPos.y + _buttonHeight)) {
        _isHoveringButton = true;
        _helpText.setFillColor(sf::Color::Yellow);
    } else {
        _isHoveringButton = false;
        _helpText.setFillColor(sf::Color::White);
    }
    _keysList.setPosition(sf::Vector2f(mousePos.x, mousePos.y - TEXT_OFFSET));
    _popup.setPosition(sf::Vector2f(mousePos.x, mousePos.y - POPUP_OFFSET));
}

void HelpButton::draw(sf::RenderWindow *window)
{
    window->draw(_background);
    window->draw(_helpText);
    if (_isHoveringButton) {
        window->draw(_popup);
        window->draw(_keysList);
    }
}
