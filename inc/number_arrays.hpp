#pragma once
#ifndef NUMBER_ARRAY_HPP
#define NUMBER_ARRAY_HPP


#include <cstdlib>
#include <stdexcept>
#include "generator.h"


///
/// @brief This class is used for store numbers.
class NumberArray{

protected:
    int * numbers, length, max;
public:

    NumberArray(const int &length, const int & max);
    [[nodiscard]] int get(const int &index) const;
    bool set(const int &index, int value);

    ///
    /// @brief This function is used for get max value that can appear in the array.
    /// @return Max value that can appear in the array.
    [[nodiscard]] inline int getMax() const {return max;}

    inline ~NumberArray()
    {
        if (*numbers) free(numbers);
    }


};

///
/// @brief This class is used for store generated numbers.
class RandomArray: public NumberArray{

public:
    inline RandomArray(const int &length, const int & max): NumberArray(length, max)
    {
        generate_decimal(numbers,length,max);
    };
};

///
/// @brief This class is used for store numbers given by user.
class UserArray: public NumberArray{

public:
    inline UserArray(const int &length, const int & max): NumberArray(length, max){};
};


#endif //NUMBER_ARRAY_HPP