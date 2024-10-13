#pragma once
#ifndef GAME_HPP
#define GAME_HPP


#include "terminal.hpp"
#include "game.hpp"


class Numbers: public Game<int>{


private:
    const int max;

protected:
    void see(int & index) override;
    void write(int & index) override;


public:
    inline Numbers(const int &length, const int & max): Game(length), max(max)
    {
        srand(time(NULL));
        for (int i = 0; i < length; ++i)
        {
            answers->set(i, 0);
            questions->set(i, rand() % max + 0);
        }
    }

    void summary() override;

    ~Numbers() override = default;
};


#endif //GAME_HPP