#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <cstdlib>
#include <stdexcept>
#include <climits>


///
/// @brief A class for storing numbers.
/// @tparam T Type of data stored in the array.
template <class T> class Array{

private:
    T * array_data;
    const int length;
    const size_t group_size;


    ///
    /// @brief Calculates the index of the first element of the given group.
    /// @param group_index Index of an group.
    /// @return Index of the first element of the given group.
    [[nodiscard]] inline int calculateIndex(const int &group_index) const
    {
        return group_index * group_size;
    }

    ///
    /// @brief Checks if the element index is correct.
    /// @param index Index of an element.
    /// @return True if yes, false if no.
    [[nodiscard]] inline bool validateIndex(const int & index) const
    {
        return !(index < 0 || index > (length-1));
    }

    ///
    /// @brief Checks if the group index is correct.
    /// @param index Index of an group.
    /// @return True if yes, false if no.
    [[nodiscard]] inline bool validateGroupIndex(const int & group_index) const
    {
        const int index = calculateIndex(group_index);
        return validateIndex(index) && index % group_size == 0;
    }


public:

    explicit Array(const int &length, const size_t &group_size);

    [[nodiscard]] T get(const int &index) const;
    T * getGroup(const int &group_index) const;

    bool set(const int &index, T value);
    bool set(const int &group_index, T * values);

    inline ~Array()
    {
        if (*array_data) free(array_data);
    }
};


#endif //ARRAY_HPP