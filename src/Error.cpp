/*
** EPITECH PROJECT, 2020
** nts
** File description:
** error
*/

#include "Error.hpp"

Error::Error(const std::string &message, const std::string &component):
    _message(message), _component(component)
{}

std::string const &Error::getComponent(void) const { return (_component); }
const char *Error::what(void) const noexcept { return (_message.data()); }

void Error::printErr(void) const
{
    std::cout << "Error in " << _component << ":" << std::endl << "\t" << _message << std::endl;
}
