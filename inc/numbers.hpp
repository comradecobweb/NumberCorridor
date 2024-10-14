#pragma once
#ifndef GAME_HPP
#define GAME_HPP


#include "terminal.hpp"
#include "game.hpp"


template <size_t group_size = 1> class Numbers: public Game<int, group_size>{


private:
    const int max;

protected:
    void see(int & index) override;
    void write(int & index) override;


public:
    inline Numbers(const int &length, const int & max): Game<int, group_size>(length), max(max)
    {
        srand(time(nullptr));
        for (int i = 0; i < length; ++i)
        {
            this->answers->set(i, 0);
            this->questions->set(i, rand() % max + 0);
        }
    }

    void summary() override;

    ~Numbers() override = default;
};


#endif //GAME_HPP