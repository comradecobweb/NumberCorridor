#pragma once
#ifndef BASE_GAME_HPP
#define BASE_GAME_HPP


#include <chrono>
#include "terminal.hpp"


class Game{

private:
    bool finished;

protected:
    const int length;
    float recall_time;
    float memorization_time;

    virtual void see(int & index) = 0;
    virtual void write(int & index) = 0;

public:

    ///
    /// @brief This function is used to calculate percentages.
    /// @param good Good results.
    /// @param total Total results.
    /// @return Calculated percentages.
    static inline float calculatePercentages(const float &good, const float &total)
    {
        return good * 100 / total;
    }

    virtual void memorization() final;
    virtual void recall() final;
    virtual void wait() final;

    virtual void summary() = 0;

    inline explicit Game(const int length):finished(false), length(length), memorization_time(0.0f), recall_time(0.0f){};
    virtual ~Game()= default;
};


#endif //BASE_GAME_HPP