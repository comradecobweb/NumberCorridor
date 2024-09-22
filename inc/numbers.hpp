#pragma once
#ifndef GAME_HPP
#define GAME_HPP


#include "number_arrays.hpp"
#include "terminal.hpp"
#include "game.hpp"


class Numbers: public Game{

private:
    RandomArray *random;
    UserArray *user;


protected:
    void see(int & index) override;
    void write(int & index) override;


public:
    inline Numbers(const int &length, const int & max): Game(length)
    {
        random = new RandomArray(length, max);
        user = new UserArray(length, max);
    }

    void summary() override;

    inline ~Numbers() override
    {
        delete random;
        delete user;
    }
};


#endif //GAME_HPP