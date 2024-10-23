#include "main.hpp"


int main(int argc, char *argv[])
{
    using namespace std;
    if(argc > 1)
    {
        string s(argv[1]);

        if ((s=="help" || s=="-help" || s=="-h") && isLast(1,argc))
        {
            help();
        }

        else if ((s=="menu" || s=="-menu") && isLast(1,argc))
        {
            menu();
        }

        else if ((s=="debug" || s=="-debug") && isLast(1,argc))
        {
            debug();
        }

        else if (s=="play" || s=="-play" || s=="-p")
        {
            game_data data;
            for (int i = 2; i < argc; ++i)
            {
                string param(argv[i]);

                if (param=="max" || param=="-max" || param=="-m")
                {
                    if (data.max != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: max"  << endl << endl;
                        return -1;
                    }
                    int max = getNextValue(i, argc, argv);
                    if (max < 2)
                    {
                        cout << red << "Error!\t" << reset << "Invalid/undefined max value!"  << endl << endl;
                        return -1;
                    }
                    data.max = max;
                }
                else if(param=="length" || param=="-length" || param=="-l")
                {
                    if (data.length != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: length"  << endl << endl;
                        return -1;
                    }
                    int length = getNextValue(i, argc, argv);
                    if (length < 1)
                    {
                        cout << red << "Error!\t" << reset << "Invalid/undefined length value!" << endl << endl;
                        return -1;
                    }
                    data.length = length;
                }
                else if(param=="size" || param=="-size" || param=="-s")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size"  << endl << endl;
                        return -1;
                    }
                    int size = getNextValue(i, argc, argv);
                    if (size < 1 || size > 3)
                    {
                        cout << red << "Error!\t" << reset << "Invalid/undefined size value!" << endl << endl;
                        return -1;
                    }
                    data.group_size = size;
                }

                else if(param=="single" || param=="-single")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size"  << endl << endl;
                        return -1;
                    }
                    data.group_size = 1;
                }
                else if(param=="PA" || param=="-PA" || param=="pa" || param=="-pa")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size"  << endl << endl;
                        return -1;
                    }
                    data.group_size = 2;
                }
                else if(param=="PAO" || param=="-PAO" || param=="pao" || param=="-pao")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size"  << endl << endl;
                        return -1;
                    }
                    data.group_size = 3;
                }

                else
                {
                    cout << red << "Error!\t" << reset << "Unknown game argument: " << argv[i] << endl << endl;
                    return -1;
                }
            }
            GameBuilder(data).run();
            clear();
        }

        else
        {
            cout << red << "Error!\t" << reset << "Unknown argument: " << argv[argc - 1] << endl << endl;
            return -1;
        }
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
/// @brief Gets the next element of an array.
/// @param index Current element. The function increments it twice.
/// @param argc Array size.
/// @param argv Array.
/// @return The next element from the array, or -1 if the last one is current.
int getNextValue(int &index, const int &argc, char *argv[])
{
    using namespace std;

    if (isLast(index, argc)) return -1;
    ++index;

    string s(argv[index]);

    if (!is_number(s)) return -1;
    int i;
    stringstream stream;

    stream << s;
    stream >> i;
    return i;
}