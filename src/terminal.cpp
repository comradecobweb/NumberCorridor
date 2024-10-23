#include "terminal.hpp"


///
/// @brief This function is used to read single numbers from the user.
/// @return The loaded number or -1 if an invalid value is entered (e.g. letter).
int read()
{
    using namespace std;

    string input;
    int i;

    cin.clear();
    cout << cyan << ">" << reset << " ";

    getline(cin, input);

    if (!is_number(input)) return -1;


    stringstream stream;

    stream << input;
    stream >> i;

    if (i == INT_MAX || i == INT_MIN) return -1;


    return i;
}

///
/// @brief This function is used to read single numbers from the user.
/// @param color Specifies the color of characters entered by the user.
/// @return The loaded number or -1 if an invalid value is entered (e.g. letter).
int read(colors color)
{
    using namespace std;

    string input;
    int i;

    cin.clear();
    cout << cyan << ">" << reset << " " << color;

    getline(cin, input);

    cout << reset;

    if (!is_number(input)) return -1;


    stringstream stream;

    stream << input;
    stream >> i;

    if (i == INT_MAX || i == INT_MIN) return -1;


    return i;
}