#pragma once
#ifndef NUMBERS_HPP
#define NUMBERS_HPP


#include "terminal.hpp"
#include "game.hpp"


///
/// @brief The class responsible for the number memorization game
class Numbers : public Game<int> {

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
            Game<int>(length, group_size), max(max) {
        srand(time(nullptr));
        for (int i = 0; i < length; ++i) {
            this->answers->set(i, 0);
            this->questions->set(i, rand() % max + 0);
        }
    }

    void summary() override;

    ~Numbers() override = default;
};

#endif //NUMBERS_HPP