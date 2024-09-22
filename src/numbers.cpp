#include "numbers.hpp"


///
/// This function is responsible for reading a single number from the user.
/// @param index Position of an element in the array (in the game).
void Numbers::see(int & index)
{
    using namespace std;
    int answer;

    while (true)
    {
        clear();
        cout << "Number " << yellow << (index + 1) << reset << "/" << blue << length << reset << ":" << endl
             << endl << "\t" << magenta << random->get(index) << reset << endl << endl;

        if (index != length)
        {
            cout << "Write " << cyan << 1 << reset << " to see next." << endl;
        }
        if (index != 0)
        {
            cout << "Write " << cyan << 2 << reset << " to see previous." << endl;
        }

        answer = read();


        if (answer == 1 && (index != length))
        {
            break;
        }
        if (answer == 2 && (index != 0))
        {
            index -= 2;
            break;
        }
    }
}

///
/// This function is responsible for reading a single number from the user.
/// @param index Position of an element in the array (in the game).
void Numbers::write(int & index)
{
    using namespace std;
    int answer;

    while (true)
    {
        clear();
        cout << "Number " << yellow << (index + 1) << reset << "/" << blue << length << reset << ":" << endl
             << endl << "\t";
        answer = read(magenta);

        if (answer <= user->getMax()-1)
        {
            if (user->set(index,answer))
            {
                break;
            }
        }
    }
}

///
/// @brief This function is responsible for the summary screen.
void Numbers::summary()
{
    using namespace std;
    int wrong = 0;

    clear();
    cout << "Thank you! Your results: " << endl << endl << endl;

    for (int i = 0; i != length; ++i)
    {
        if (random->get(i)==user->get(i))
        {
            cout <<yellow << (i+1) << reset << ".\t" << green << random -> get(i) << reset << endl;
        }

        else
        {
            cout <<yellow << (i+1) << reset
            << ".\t" << red << user -> get(i) << reset
            << "\t" << green << random -> get(i) << reset << endl;
            wrong++;
        }
    }

    float score = calculatePercentages(static_cast<float>(length - wrong),
                                       static_cast<float>(length));

    cout << endl << endl << "Summary:" << endl << endl << endl
    << "Good:\t\t" << green << length-wrong << reset << endl
    << "Wrong:\t\t" << red << wrong << reset << endl
    << "Accuracy:\t";

    if (score > 50.0f)
    {
        cout << green;
    }else
    {
        cout << red;
    }

    cout << score << "%" << reset << endl << endl << endl << "Time stats (in " << yellow << "seconds"
    << reset << "):" << endl << endl << endl
    << magenta << "Memorization"<< reset <<" time:\t" << blue << memorization_time
    << reset << endl
    << cyan << "Recall"<< reset <<" time:\t\t" << blue << recall_time << reset << endl
    << green << "Total" << reset << " time:\t\t" << blue << (memorization_time+recall_time)
    << reset <<  endl << endl

    << "Single number " << magenta << "memorization" << reset << " time:\t" << blue <<
    (memorization_time/static_cast<float>(length)) << reset << endl
    << "Single number " << cyan << "recall" << reset << " time:\t\t" << blue << (recall_time/static_cast<float>(length))
    << reset << endl << endl

    << endl <<"Write something to close summary:" << endl;
    read();
}