#pragma once
#ifndef GAME_BUILDER_HPP
#define GAME_BUILDER_HPP


#include "terminal.hpp"
#include "game.hpp"
#include "numbers.hpp"


enum modes {decimal, binary};


///
/// @brief This class is used for run the game.
class GameBuilder{

private:
    modes mode;
    int length;
    int max;
    bool grouped = false;
    int group_size;

    void readMode();
    void readLength();
    void readMax();
    void readGrouped();
    void readGroupSize();
public:
    GameBuilder();
    explicit GameBuilder(const int & max);
    GameBuilder(const int & max, const int & length);
    int run();
};



#endif //GAME_BUILDER_HPP