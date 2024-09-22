#include "number_arrays.hpp"


///
/// @brief Constructor of NumberArray class.
/// @param length Length of the array.
/// @param max The maximum value that can appear in the array.
/// @throw std::bad_alloc If can't allocate memory for the array, or length is incorrect.
/// @throw std::invalid_argument if max is invalid.
NumberArray::NumberArray(const int &length, const int &max):length(length), max(max)
{
    if (length < 0) throw std::bad_alloc();
    if (max < 0) throw std::invalid_argument("Max value can't be less than 1!");


    numbers = (int *)malloc(sizeof(numbers)*length);
    if (!numbers)
    {
        throw std::bad_alloc();
    }

    for (int i = 0; i != length; ++i)
    {
        numbers[i] = -1;
    }
}

///
/// @brief This function is used for get elements of the array.
/// @param index Position of an element in the array.
/// @return Selected value or -1 if the index is invalid.
int NumberArray::get(const int &index) const
{
    if (index < 0 || index > (length-1)){
        return -1;
    } else{
        return numbers[index];
    }
}

///
/// @brief This function is used for set elements of the array.
/// @param index Position of an element in the array.
/// @param value The value that will be inserted into the array.
/// @return True on success, false on invalid index or invalid value.
bool NumberArray::set(const int &index, int value)
{
    if ( !(index < 0 || index > (length-1)) && value > -1 && value <= max){

        numbers[index] = value;

        return true;
    } else{
        return false;
    }
}