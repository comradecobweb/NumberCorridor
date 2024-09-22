#include "game.hpp"


///
/// @brief This function is responsible for the memorization screen.
void Game::memorization()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    for (int i = 0; i != length; ++i)
    {
        see(i);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    memorization_time += (float) duration.count();
}

///
/// @brief This function is responsible for the recall screen.
void Game::recall()
{
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    for (int i = 0; i != length; ++i)
    {
        write(i);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    recall_time += (float) duration.count();
    finished = true;
}

///
/// @brief This function is responsible for the wait screen.
///
/// This screen appears between the remember and recall screens, and after the recall screen.
/// It has 2 versions depending on when it appears.
void Game::wait()
{
    using namespace std;
    bool b = true;

    if (finished)
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