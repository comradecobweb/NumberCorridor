#include "generator.h"


///
/// @brief This function is used for generate elements for the array.
/// @param array Pointer to the array.
/// @param length Length of the array.
/// @param max The maximum value that can appear in the array.
void generate_decimal(int * array, const int length, const int max)
{
    srand(time(NULL));

    for (int i = 0; i != length; ++i)
    {
        array[i] = rand() % max + 0;
    }
}