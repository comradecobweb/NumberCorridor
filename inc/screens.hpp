#pragma once
#ifndef SCREENS_HPP
#define SCREENS_HPP


#include "terminal.hpp"
#include "game_builder.hpp"


void menu();

void debug();

void help();

void version();

///
/// @return Current Current version of NumberCorridor.
inline std::string get_version()
{
    return "0.2.0";
}

#endif //SCREENS_HPP