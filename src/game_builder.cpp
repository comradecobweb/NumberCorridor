#include "game_builder.hpp"


///
/// @brief Reads a mode from the user.
/// @return Mode.
int game_data::readMode()
{
    using namespace std;
    int answer;
    while (true)
    {
        clear();
        cout << "Write " << cyan << 1 << reset << " to memorize decimal numbers."<< endl;
        cout << "Write " << cyan << 2 << reset << " to memorize binary numbers."<< endl;
        answer = read();
        if (answer==1 || answer==2)
        {
            break;
        }
    }
    return answer;
}

///
/// @biref Reads the number of digits to remember.
/// @return Number of digits to remember.
int game_data::readLength()
{
    using namespace std;
    int answer;
    while (true)
    {
        clear();
        cout << "Write how many numbers do you want to remember (minimal is 1, max is 100000): " << endl;
        answer = read();
        if (answer > 0 && answer < 100001)
        {
            break;
        }
    }
    return answer;
}

///
/// @brief Reads a max value from the user.
/// @return Given value.
int game_data::readMax()
{
    using namespace std;
    int answer;
    while (true)
    {
        clear();
        cout << "Write max number do you want to remember (minimal is 2): " << endl;
        answer = read();
        if (answer > 2 && answer != INT_MAX)
        {
            break;
        }
    }
    return answer;
}

///
/// @brief Reads a group size from the user.
/// @return Group size.
int game_data::readGroupSize()
{
    using namespace std;
    int answer;
    while (true)
    {
        clear();
        cout << "Write " << cyan << 1 << reset << " to memorize single numbers." << endl
             << "Write " << cyan << 2 << reset << " to memorize using PA." << endl
             << "Write " << cyan << 3 << reset << " to memorize using PAO." << endl;
        answer = read();
        if (answer == 1 || answer == 2 || answer == 3)
        {
            return answer;
        }
    }
}

///
/// @brief Undefined values in game_data (-1) are set to user-supplied values.
void game_data::initialize()
{
    if(group_size == -1)
    {
        group_size = readGroupSize();
    }

    if (length == -1)
    {
        length = readLength();
    }

    if (max == -1)
    {
        const int mode = readMode();
        if (mode==DECIMAL)
        {
            max = readMax();
        }
        else
        {
            max = 2;
        }
    }
}


///
/// @brief Constructor of the GameBuilder class.
/// @param max Upper limit of generated numbers.
/// @param length Number of numbers to remember.
/// @param group_size 1, 2, or 3 for single, PA and PAO games respectively.
/// @throws std::invalid_argument If max, length, or group_size are incorrect.
GameBuilder::GameBuilder(const int &max, const int &length, const int &group_size)
{
    data.length = length;
    data.max = max;
    data.group_size = group_size;
    if (!data.isInitialized()) data.initialize();
    if (!data.isValid()) throw std::invalid_argument("Invalid GameBuilder parameters!");
}

///
/// @brief Constructor of the GameBuilder class.
/// @param param_data game_data structure.
/// @throws std::invalid_argument If max, length, or group_size in param_data are incorrect.
GameBuilder::GameBuilder(const game_data &param_data)
{
    data.length=param_data.length;
    data.max=param_data.max;
    data.group_size=param_data.group_size;
    if (!data.isInitialized()) data.initialize();
    if (!data.isValid()) throw std::invalid_argument("Invalid GameBuilder parameters!");
}

///
/// @brief Starts the game and catches any exceptions thrown by it.
void GameBuilder::run()
{
    using namespace std;
    try
    {
        switch (data.group_size)
        {
            case 1:
                single();
                break;
            case 2:
                PA();
                break;
            case 3:
                PAO();
                break;
        }
    }
    catch(bad_alloc &b)
    {
        clear();
        cout << red << "Error:" << reset << endl
             << "Could not allocate memory!" << endl << endl;
        exit(-1);
    }
    catch(invalid_argument &i)
    {
        clear();
        cout << red << "Error:" << reset << endl
             << "Internal error!" << endl << endl;
        exit(-1);
    }
}

///
/// @brief The function is responsible for starting the single numbers game.
void GameBuilder::single() const
{
    auto * game = new Numbers<1>(data.length, data.max);
    game->memorization();
    game->wait();
    game->recall();
    game->wait();
    game->summary();
    delete game;
}

///
/// @brief The function is responsible for starting the PA game.
void GameBuilder::PA() const
{
    auto * game = new Numbers<2>(data.length, data.max);
    game->memorization();
    game->wait();
    game->recall();
    game->wait();
    game->summary();
    delete game;
}

///
/// @brief The function is responsible for starting the PAO game.
void GameBuilder::PAO() const
{
    auto * game = new Numbers<3>(data.length, data.max);
    game->memorization();
    game->wait();
    game->recall();
    game->wait();
    game->summary();
    delete game;
}