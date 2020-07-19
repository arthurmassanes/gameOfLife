/*
** EPITECH PROJECT, 2020
** nts
** File description:
** error class
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <iostream>

class Error: public std::exception
{
private:
    std::string _message;
    std::string _component;
public:
    Error(const std::string &message, const std::string &component = "Unknown");
    std::string const &getComponent(void) const;
    const char *what(void) const noexcept override;
    void printErr(void) const;
};


#endif
