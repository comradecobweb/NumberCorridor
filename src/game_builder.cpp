#include "game_builder.hpp"

///
/// @brief Reads a mode from the user. It does not return it, but saves it to the appropriate class member.
void GameBuilder::readMode()
{
    using namespace std;
    int answer;
    while (true)
    {
        clear();
        cout << "Write " << cyan << 1 << reset << " to memorize decimal numbers."<< endl;
        cout << "Write " << cyan << 2 << reset << " to memorize binary numbers."<< endl;
        answer = read();
        if (answer==1)
        {
            mode = decimal;
            break;
        }
        if (answer==2)
        {
            mode = binary;
            max = 2;
            break;
        }
    }
}

///
/// @biref Reads a length from the user. It does not return it, but saves it to the appropriate class member.
void GameBuilder::readLength()
{
    using namespace std;
    while (true)
    {
        clear();
        cout << "Write how many numbers do you want to remember (minimal is 1, max is 100000): " << endl;
        length = read();
        if (length > 0 && length < 100001)
        {
            break;
        }
    }
}

///
/// @brief Reads a max value from the user. It does not return it, but saves it to the appropriate class member.
void GameBuilder::readMax()
{
    using namespace std;
    while (true)
    {
        clear();
        cout << "Write max number do you want to remember (minimal is 1): " << endl;
        max = read();
        if (max > 0)
        {
            break;
        }
    }
}

///
/// @brief Reads a grouped from the user. It does not return it, but saves it to the appropriate class member.
void GameBuilder::readGrouped()
{
    using namespace std;
    int answer;
    while (true)
    {
        clear();
        cout << "Write " << cyan << 1 << reset << " to use number groups."<< endl;
        cout << "Write " << cyan << 2 << reset << " to don't use number groups."<< endl;
        answer = read();
        if (answer==1)
        {
            grouped = true;
            break;
        }
        if (answer==2)
        {
            grouped = false;
            break;
        }
    }
}

///
/// @brief Reads a group size from the user. It does not return it, but saves it to the appropriate class member.
void GameBuilder::readGroupSize()
{
    using namespace std;
    while (true)
    {
        clear();
        cout << "Write how many numbers do you want to remember (minimal is 2, max is 100000): " << endl;
        group_size = read();
        if (group_size > 1 && group_size < 100001)
        {
            break;
        }
    }
}

///
/// @brief This function is used for run the game.
/// @return 0 on success, otherwise -1.
int GameBuilder::run()
{
    using namespace std;
    Game *game;
    try
    {

        if (grouped)
        {
            switch (mode) {
                case decimal:
                    return -1;
                    break;
                case binary:
                    return -1;
                    break;
            }
        }else
        {
            switch (mode) {
                case decimal:
                    game = new Numbers(length, max);
                    break;
                case binary:
                    game = new Numbers(length, 2);
                    break;

            }
        }


    }catch (bad_alloc &b)
    {
        clear();
        cout << red << "Error:" << reset << endl
             << "Wrong length value!" << endl << endl
             << "Write something to continue:" << endl;
        read();
        return -1;
    }catch (invalid_argument &i)
    {
        clear();
        cout << red << "Error:" << reset << endl
             << "Wrong max value!" << endl << endl
             << "Write something to continue:" << endl;
        read();
        return -1;
    }

    game->memorization();
    game->wait();
    game->recall();
    game->wait();
    game->summary();
    delete game;
    return 0;
}

///
/// @brief Constructor of GameBuilder class.
GameBuilder::GameBuilder()
{
    readMode();
    readLength();

    if (mode==decimal)
    {
        readMax();
    }


    //readGrouped();
    if (grouped)
    {
        readGroupSize();
    }
}

///
/// @brief Constructor of GameBuilder class.
/// @param max The maximum value that can appear in the array in the game.
GameBuilder::GameBuilder(const int &max)
{
    if (max<3)
    {
        this->max = 2;
        mode = binary;
    }else
    {
        this->max=max;
        mode = decimal;
    }

    readLength();
    //readGrouped();
    if (grouped)
    {
        readGroupSize();
    }
}

///
/// @brief Constructor of GameBuilder class.
/// @param max The maximum value that can appear in the array in the game.
/// @param length Length of the array in the game.
GameBuilder::GameBuilder(const int &max, const int &length):length(length)
{
    if (max<3)
    {
        this->max = 2;
        mode = binary;
    }else
    {
        this->max=max;
        mode = decimal;
    }

    //readGrouped();
    if (grouped)
    {
        readGroupSize();
    }
}