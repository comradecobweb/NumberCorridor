#pragma once
#ifndef TERMINAL_HPP
#define TERMINAL_HPP


#if ! (defined(_WIN32) || defined(__linux__))
#error Only Windows and Linux are supported!
#endif


#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <climits>
#include <algorithm>


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


///
/// @brief This enum contains colors that are available to use.
    enum colors {
        red, green, yellow, blue, magenta, cyan, reset
    };


    ///
    /// @brief This function is used for clean the screen.
    inline void clear() {
#ifdef _WIN32
        system("cls");
#endif
#ifdef __linux__
        system("clear");
#endif
    }

    ///
    /// @brief This function is used for check is string a number.
    /// @param s String to check.
    /// @return True if yes, false if no.
    inline bool is_number(const std::string &s) {
        return !s.empty() && std::find_if(s.begin(),
                                          s.end(), [](unsigned char c) { return !std::isdigit(c); })
                             == s.end();
    }

    static std::ostream &operator<<(std::ostream &os, const colors &c) {
        switch (c) {
            case red:
                os << RED;
                break;
            case green:
                os << GREEN;
                break;
            case yellow:
                os << YELLOW;
                break;
            case blue:
                os << BLUE;
                break;
            case magenta:
                os << MAGENTA;
                break;
            case cyan:
                os << CYAN;
                break;
            case reset:
                os << RESET;
                break;
        }
        return os;
    }

    int read();
    int read(colors color);


#endif //TERMINAL_HPP