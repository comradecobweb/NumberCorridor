#pragma once
#ifndef GAME_HPP
#define GAME_HPP


#include "terminal.hpp"
#include "game.hpp"
#include <random>


///
/// @brief The class responsible for the number memorization game
class Numbers : public Game<int>
{

private:
    const int max;

protected:
    void see(int &index) override;

    void write(int &index) override;

public:

    ///
    /// @brief Constructor of the Numbers class.
    /// @param length Number of numbers to remember.
    /// @param max Upper limit of generated numbers (the largest number generated will be max-1).
    ///
    /// Generates random numbers to remember and sets the answer values to 0.
    inline Numbers(const int &length, const int &max, const size_t &group_size = 1) :
            Game<int>(length, group_size), max(max)
    {
        using namespace std;
        random_device rd;
        mt19937 mt(rd());
        std::uniform_int_distribution<std::mt19937::result_type> generate(0, max - 1);

        for (int i = 0; i < length; ++i)
        {
            this->answers->set(i, 0);
            this->questions->set(i, (int) generate(mt));
        }
    }

    void summary() override;

    ~Numbers() override = default;
};

#endif //GAME_HPP