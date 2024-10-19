#pragma once
#ifndef GAME_HPP
#define GAME_HPP


#include "terminal.hpp"
#include "game.hpp"


///
/// @brief The class responsible for the number memorization game
/// @tparam group_size Group size, 1 for single, 2 for PA, 3 for PAO. Default is 1.
template <size_t group_size = 1> class Numbers: public Game<int, group_size>{


private:
    const int max;

protected:
    void see(int & index) override;
    void write(int & index) override;


public:

    ///
    /// @brief Constructor of the Numbers class.
    /// @param length Number of numbers to remember.
    /// @param max Upper limit of generated numbers (the largest number generated will be max-1).
    ///
    /// Generates random numbers to remember and sets the answer values to 0.
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