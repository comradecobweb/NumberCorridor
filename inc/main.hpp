#pragma once
#ifndef MAIN_HPP
#define MAIN_HPP


#include <iostream>
#include <string>
#include "terminal.hpp"
#include "numbers.hpp"
#include "game_builder.hpp"


int main(int argc, char **argv);
static void menu();
static void help();

///
/// @brief Checks if the current element is the last element of an array of elements.
/// @param index Current element.
/// @param argc Array size (count of elements).
/// @return True if yes, false if no.
inline bool isLast(const int &index, const int & argc)
{
    return index == argc - 1;
}

int getNextValue(int &index, const int &argc, char *argv[]);


#endif //MAIN_HPP