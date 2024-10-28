#include "main.hpp"


int main(int argc, char *argv[])
{
    using namespace std;
    if (argc > 1)
    {
        const string s(argv[1]);

        if ((s == "help" || s == "-help" || s == "--help") && isLast(1, argc))
        {
            help();
        }

        else if ((s == "menu" || s == "-menu" || s == "--menu") && isLast(1, argc))
        {
            menu();
        }

        else if ((s == "debug" || s == "-debug" || s == "--debug") && isLast(1, argc))
        {
            debug();
        }

        else if ((s == "version" || s == "-version" || s == "--version") && isLast(1, argc))
        {
            version();
        }

        else if (s == "play" || s == "-play" || s == "--play" || s == "-p" || s == "--p")
        {
            game_data data;
            for (int i = 2; i < argc; ++i)
            {
                const string param(argv[i]);

                if (param == "max" || param == "-max" || param == "--max" || param == "-m" || param == "--m")
                {
                    if (data.max != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: max" << endl << endl;
                        return -1;
                    }
                    const int max = getNextValue(i, argc, argv);
                    if (max < 2)
                    {
                        cout << red << "Error!\t" << reset << "Invalid/undefined max value!" << endl << endl;
                        return -1;
                    }
                    data.max = max;
                }
                else if (param == "dec" || param == "-dec" || param == "--dec")
                {
                    if (data.max != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: max" << endl << endl;
                        return -1;
                    }
                    data.max = 10;
                }
                else if (param == "bin" || param == "-bin" || param == "--bin")
                {
                    if (data.max != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: max" << endl << endl;
                        return -1;
                    }
                    data.max = 2;
                }

                else if (param == "length" || param == "-length" || param == "--length" || param == "-l" ||
                         param == "--l")
                {
                    if (data.length != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: length" << endl << endl;
                        return -1;
                    }
                    const int length = getNextValue(i, argc, argv);
                    if (length < 1)
                    {
                        cout << red << "Error!\t" << reset << "Invalid/undefined length value!" << endl << endl;
                        return -1;
                    }
                    data.length = length;
                }
                else if (param == "size" || param == "-size" || param == "--size" || param == "-s" || param == "--s")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size" << endl << endl;
                        return -1;
                    }
                    const int size = getNextValue(i, argc, argv);
                    if (size < 1)
                    {
                        cout << red << "Error!\t" << reset << "Invalid/undefined size value!" << endl << endl;
                        return -1;
                    }
                    data.group_size = size;
                }

                else if (param == "single" || param == "-single" || param == "--single")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size" << endl << endl;
                        return -1;
                    }
                    data.group_size = 1;
                }
                else if (param == "PA" || param == "-PA" || param == "--PA" || param == "pa" || param == "-pa" ||
                         param == "--pa")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size" << endl << endl;
                        return -1;
                    }
                    data.group_size = 2;
                }
                else if (param == "PAO" || param == "-PAO" || param == "--PAO" || param == "pao" || param == "-pao" ||
                         param == "--pao")
                {
                    if (data.group_size != -1)
                    {
                        cout << red << "Error!\t" << reset << "Duplicate argument: size" << endl << endl;
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

    return to_int(argv[index]);
}