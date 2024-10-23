#include "screens.hpp"

///
/// @brief This function is responsible for the menu screen.
void menu()
{
    using namespace std;


    while (true) {
        clear();

        cout << endl << endl
             << "\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl
             << "\t\t| " << magenta << "Number Corridor" << reset << " by " << yellow << "Comrade Cobweb"
             << reset << " |" << endl
             << "\t\t|                                   |" << endl
             << "\t\t| Version: " << red << "alpha" << reset << "                    |" << endl
             << "\t\t| License: " << green << "Apache-2.0" << reset << "               |" << endl
             << "\t\t|                                   |" << endl
             << "\t\t| " << blue << " https://github.com/comradecobweb" << reset << " |" << endl
             << "\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl << endl << endl
             << "Write " << cyan << 1 << reset << " to play standard game." << endl
             << "Write " << cyan << 2 << reset << " to play all-custom mode." << endl
             << "Write " << cyan << 3 << reset << " to play custom length decimal mode (with max value "
             << cyan << 10 << reset << ")." << endl
             << "Write " << cyan << 4 << reset << " to play custom length binary mode."<< endl
             << "Write " << cyan << 5 << reset << " to exit." << endl << endl;


        switch (read()) {
            case 0:
                debug();
                break;
            case 1:
                GameBuilder(10,7, 1).run();
                break;
            case 2:
                GameBuilder().run();
                break;
            case 3:
                GameBuilder(10).run();
                break;
            case 4:
                GameBuilder(2).run();
                break;
            case 5:
                clear();
                exit(0);
        }
    }
}

///
/// @brief This function is responsible for the debug screen.
void debug()
{
    using namespace std;

    clear();

    const int clear_supported = system("clear");
    const int cls_supported = system("cls");


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

///
/// @brief This function is responsible for the help screen.
void help()
{
    using namespace std;

    cout
    << endl
    <<  magenta << "Number Corridor" << reset << " by: " << yellow << "Comrade Cobweb"<< reset << endl << endl <<endl
    << "Use without arguments to play. For more information see:" << endl
    <<  blue << "https://github.com/comradecobweb/NumberCorridor" << reset << endl;
}

///
/// @brief This function is responsible for the version screen.
void version()
{
    using namespace std;
    cout <<endl << red << "alpha" << reset << endl;
}