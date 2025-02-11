#pragma once
#ifndef GAME_HPP
#define GAME_HPP


#include <chrono>
#include "terminal.hpp"
#include "array.hpp"


///
/// @brief Abstract game class.
/// @tparam T Type of stored values.
template<class T>
class Game {
private:
    bool finished;
    float recall_time;
    float memorization_time;

protected:
    const int length;
    const size_t group_size;

    Array<T> *questions;
    Array<T> *answers;

    virtual void see(int &index) = 0;

    virtual void write(int &index) = 0;

    ///
    /// @brief Calculates the result in percentage.
    /// @param wrong Number of wrong answers.
    /// @return The result is calculated as a percentage.
    [[nodiscard]] inline float getScore(const int &wrong) const {
        return ((static_cast<float>(length) - static_cast<float>(wrong)) * 100.0f / static_cast<float>(length));
    }

    [[nodiscard]] inline float getTotalTime() const {
        return memorization_time + recall_time;
    }

    [[nodiscard]] inline float getSingleNumberMemorizationTime() const {
        return memorization_time / static_cast<float>(length);
    }

    [[nodiscard]] inline float getSingleNumberRecallTime() const {
        return recall_time / static_cast<float>(length);
    }

    [[nodiscard]] inline float getMemorizationTime() const {
        return memorization_time;
    }

    [[nodiscard]] inline float getRecallTime() const {
        return recall_time;
    }

    [[nodiscard]] inline float isFinished() const {
        return finished;
    }

    [[nodiscard]] int countGroups() const;

    [[nodiscard]] int getGroupSize(const int &group_index) const;

public:
    virtual void memorization() final;

    virtual void recall() final;

    virtual void wait();

    virtual void summary() = 0;

    inline explicit Game(const int &length, size_t group_size = 1) :
            finished(false), length(length), group_size(group_size), memorization_time(0.0f), recall_time(0.0f) {
        questions = new Array<T>(length, group_size);
        answers = new Array<T>(length, group_size);
    };

    virtual ~Game() {
        delete questions;
        delete answers;
    };
};

#endif //GAME_HPP