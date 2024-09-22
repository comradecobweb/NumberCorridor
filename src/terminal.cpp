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

///
/// @brief This function is responsible for the debug screen.
void debug()
{
    using namespace std;

    clear();

    int clear_supported = system("clear");
    int cls_supported = system("cls");


    clear();

    cout << "Welcome in secret debug screen!" << endl << endl


         << "Color test:" << endl << endl
         << red << "red:     \tHello, World!" << reset << endl
         << green << "green:   \tHello, World!" << reset << endl
         << yellow << "yellow:  \tHello, World!" << reset << endl
         << blue << "blue:    \tHello, World!" << reset << endl
         << magenta << "magenta: \tHello, World!" << reset << endl
         << cyan << "cyan:    \tHello, World!" << reset << endl
         << "white:   \tHello, World!" << endl << endl;

    cout << "Command test:" << endl << endl
         << "Is " << blue << "cls" << reset << " supported: ";

    if (cls_supported)
    {
        cout << red << "\tNO" << reset;
    } else
    {
        cout << green << "\tYES" << reset;
    }

    cout << endl << "Is " << blue << "clear" << reset << " supported: ";

    if (clear_supported)
    {
        cout << red << "\tNO" << reset;
    } else
    {
        cout << green << "\tYES" << reset;
    }

    cout << endl << endl << "Compilation:" << endl << endl
         << magenta << "\tTime:\t" << reset << __TIME__ << endl
         << magenta << "\tDate:\t" << reset << __DATE__ << endl
         << endl << "Other information:" << endl << endl
         << cyan << "\tINT_MAX:\t" << reset << yellow << INT_MAX << reset << endl
         << cyan << "\tINT_MIN:\t" << reset << yellow << INT_MIN << reset << endl
         << endl << endl << "Write something to close debug:" << endl;

    read();
}