#include "game.hpp"


///
/// @brief This function is responsible for the memorization screen.
template <class T>
void Game<T>::memorization()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    for (int i = 0; i != countGroups(); ++i)
    {
        see(i);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    memorization_time += (float) duration.count();
}

///
/// @brief This function is responsible for the recall screen.
template <class T>
void Game<T>::recall()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    for (int i = 0; i != countGroups(); ++i)
    {
        write(i);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    recall_time += (float) duration.count();
    finished = true;
}

///
/// @brief Counts groups.
/// @return Number of groups.
template <class T>
int Game<T>::countGroups() const
{
    if (length % group_size != 0)
    {
        return length/group_size + 1;
    }
    else
    {
        return length/group_size;
    }
}

///
/// @brief Calculates the group size (taking into account any irregular size of the last group).
/// @param group_index Index of a group in the Array.
/// @return Group size.
template <class T>
int Game<T>::getGroupSize(const int &group_index) const
{
    if (group_index==countGroups() - 1)
    {
        const int remainder = length % group_size;

        if (remainder==0)
        {
            return group_size;
        }
        else
        {
            return remainder;
        }
    }
    else
    {
        return group_size;
    }
}

///
/// @brief This function is responsible for the wait screen.
///
/// This screen appears between the remember and recall screens, and after the recall screen.
/// It has 2 versions depending on when it appears.
template <class T>
void Game<T>::wait()
{
    using namespace std;
    bool b = true;

    if (isFinished())
    {
        while (b)
        {
            clear();
            cout << blue << "Waiting..." << reset << endl << endl
                << "Write " << cyan << 1 << reset << " to continue." << endl
                 << "Write " << cyan << 2 << reset << " to return to the memorize screen." << endl
                 << "Write " << cyan << 3 << reset << " to return to the recall screen." << endl
                 << "Write " << cyan << 4 << reset << " to exit the app. " << endl;

            switch (read())
            {
                case 1:
                    b = false;
                    break;
                case 2:
                    memorization();
                    break;
                case 3:
                    recall();
                    break;

                case 4:
                    exit(0);

            }
        }
    }
    else
    {
        while (b)
        {
            clear();
            cout << blue << "Waiting..." << reset << endl << endl
                << "Write " << cyan << 1 << reset << " to continue." << endl
                << "Write " << cyan << 2 << reset << " to return to the memorize screen." << endl
                << "Write " << cyan << 3 << reset << " to exit the app. " << endl;

            switch (read())
            {
                case 1:
                    b = false;
                    break;
                case 2:
                    memorization();
                    break;
                case 3:
                    exit(0);
            }
        }
    }
}

template class Game<int>;