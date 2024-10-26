#include "terminal.hpp"


///
/// @brief Converts string to int.
/// @param s String to convert.
/// @return Converted value or -1 if string is invalid.
int to_int(const std::string &s)
{
    using namespace std;

    if (!is_number(s)) return -1;

    int i;
    stringstream stream;

    stream << s;
    stream >> i;

    if (i == INT_MAX || i == INT_MIN) return -1;
    if (i < 0) return -1;

    return i;
}

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

    return to_int(input);
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

    return to_int(input);
}