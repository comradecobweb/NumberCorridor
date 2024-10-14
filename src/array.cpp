#include "array.hpp"


///
/// @brief Constructor of NumberArray class.
/// @param length Length of the array.
/// @param group_size Size of groups in the array.
/// @throw std::bad_alloc If can't allocate memory for the array.
/// @throw std::invalid_argument() If group_size, or length are incorrect.
template <class T>
Array<T>::Array(const int &length, const size_t &group_size):length(length), group_size(group_size)
{
    if (length <= 0) throw std::invalid_argument("Array length must be greater than 0!");
    if (group_size == 0) throw std::invalid_argument("group_size in Array must be greater than 0!");


    array_data = (T *)malloc(sizeof(array_data)*length);
    if (!array_data)
    {
        throw std::bad_alloc();
    }
}

///
/// @brief This function is used for get elements of the array.
/// @param index Position of an element in the array.
/// @return Selected value or -1 if the index is invalid.
template <class T>
T Array<T>::get(const int &index) const
{
    if (validateIndex(index))
    {
        return array_data[index];
    }
    else
    {
        return (T)-1;
    }
}

///
/// @brief This function is used for get groups of the array.
/// @param group_index Position of an group in the array.
/// @return Selected group or nullptr if the index is invalid or cannot allocate memory.
template <class T>
T *Array<T>::getGroup(const int &group_index) const
{
    using namespace std;

    if (validateGroupIndex(group_index))
    {
        T * array =(T *) malloc(sizeof(T)*group_size);

        if (!array)
        {
            return nullptr;
        }

        const int index = calculateIndex(group_index);

        for (int i = index, j = 0; i < index + group_size; i++, j++)
        {
            array[j] = array_data[i];
        }

        return array;
    }
    else
    {
        return nullptr;
    }
}

///
/// @brief This function is used for set elements of the array.
/// @param index Position of an element in the array.
/// @param value The value that will be inserted into the array.
/// @return True on success, false on invalid index.
template <class T>
bool Array<T>::set(const int &index, T value)
{
    if (validateIndex(index))
    {
        array_data[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}

///
/// @brief This function is used for set elements of the array.
/// @param index Position of an element in the array.
/// @param value The value that will be inserted into the array.
/// @return True on success, false on invalid index or invalid value.
template <>
bool Array<int>::set(const int &index, int value)
{
    if (validateIndex(index) && value != INT_MAX && value != INT_MIN)
    {

        array_data[index] = value;

        return true;
    }
    else
    {
        return false;
    }
}

///
/// @brief This function is used for set elements of the array.
/// @param index Position of an group in the array.
/// @param values The values that will be inserted into the array.
/// @return True on success, false on invalid index.
template<class T>
bool Array<T>::set(const int &group_index, T *values)
{
    if (validateGroupIndex(group_index))
    {
        const int index = calculateIndex(group_index);

        for (int i = index, j = 0; i < index + group_size; i++, j++)
        {
            array_data[i] = values[j];
        }

        return true;
    }
    else
    {
        return false;
    }
}

template class Array<int>;