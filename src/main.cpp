#include "main.hpp"


int main(int argc, char **argv)
{
    using namespace std;
    if(argc > 1)
    {
        // to do in future
        menu();
    }
    else
    {
        menu();
    }
    return 0;
}

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