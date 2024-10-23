#pragma once
#ifndef GAME_BUILDER_HPP
#define GAME_BUILDER_HPP


#include "terminal.hpp"
#include "game.hpp"
#include "numbers.hpp"
#include <climits>


#define DECIMAL 1


///
/// @brief A structure containing the data of the GameBuilder class.
typedef struct game_data
{
    int group_size = -1;
    int length = -1;
    int max = -1;

    ///
    /// @brief Checks whether all fields in the structure have values different from -1.
    /// @return True if yes, false if no.
    [[nodiscard]] inline bool isInitialized() const
    {
        return group_size != -1 && length != -1 && max != -1;
    }

    ///
    /// @brief Checks if game_data fields have valid values.
    /// @return True if yes, false if no.
    [[nodiscard]] inline bool isValid() const
    {
        return group_size > 0 && group_size < 4 && length > 0 && max > 1;
    }

    void initialize();
private:
    static int readMode();
    static int readLength();
    static int readMax();
    static int readGroupSize();

} game_data;

///
/// @brief This class is used for run the game.
class GameBuilder{

private:
    void single() const;
    void PA() const;
    void PAO() const;

    game_data data;
public:
    explicit GameBuilder(const int & max = -1, const int & length = -1, const int &  group_size = -1);
    explicit GameBuilder(const game_data & param_data);
    void run();
};


#endif //GAME_BUILDER_HPP