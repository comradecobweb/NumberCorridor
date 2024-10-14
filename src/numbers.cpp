#include "numbers.hpp"


///
/// This function is responsible for reading a single number from the user.
/// @param index Position of an element in the array (in the game).
template <size_t group_size>
void Numbers<group_size>::see(int & index)
{
    using namespace std;
    int answer;

    while (true)
    {
        clear();
        cout << "Number " << yellow << (index + 1) << reset << "/" << blue << this->length << reset << ":" << endl
             << endl << "\t" << magenta << this->questions->get(index) << reset << endl << endl;

        if (index != this->length)
        {
            cout << "Write " << cyan << 1 << reset << " to see next." << endl;
        }
        if (index != 0)
        {
            cout << "Write " << cyan << 2 << reset << " to see previous." << endl;
        }

        answer = read();


        if (answer == 1 && (index != this->length))
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
template <size_t group_size>
void Numbers<group_size>::write(int & index)
{
    using namespace std;
    int answer;

    while (true)
    {
        clear();
        cout << "Number " << yellow << (index + 1) << reset << "/" << blue << this->length << reset << ":" << endl
             << endl << "\t";
        answer = read(magenta);

        if (answer <= max-1 && answer > 0)
        {
            if (this->answers->set(index, answer))
            {
                break;
            }
        }
    }
}

///
/// @brief This function is responsible for the summary screen.
template <size_t group_size>
void Numbers<group_size>::summary()
{
    using namespace std;
    int wrong = 0;

    clear();
    cout << "Thank you! Your results: " << endl << endl << endl;

    for (int i = 0; i != this->length; ++i)
    {
        if (this->questions->get(i)==this->answers->get(i))
        {
            cout <<yellow << (i+1) << reset << ".\t" << green << this->questions -> get(i) << reset << endl;
        }

        else
        {
            cout <<yellow << (i+1) << reset
            << ".\t" << red << this->answers -> get(i) << reset
            << "\t" << green << this->questions -> get(i) << reset << endl;
            wrong++;
        }
    }

    float score = this->getScore(static_cast<float>(wrong));

    cout << endl << endl << "Summary:" << endl << endl << endl
    << "Good:\t\t" << green << this->length-wrong << reset << endl
    << "Wrong:\t\t" << red << wrong << reset << endl
    << "Accuracy:\t";

    if (score > 50.0f)
    {
        cout << green;
    }else
    {
        cout << red;
    }

    cout << score << "%" << reset << endl << endl << endl << "Time stats (in "
    << yellow << "seconds"
    << reset << "):" << endl << endl << endl
    << magenta << "Memorization"<< reset <<" time:\t" << blue << this->getMemorizationTime()
    << reset << endl
    << cyan << "Recall"<< reset <<" time:\t\t" << blue << this->getRecallTime() << reset << endl
    << green << "Total" << reset << " time:\t\t" << blue << this->getTotalTime()
    << reset <<  endl << endl

    << "Single number " << magenta << "memorization" << reset << " time:\t" << blue <<
    this->singleNumberMemorizationTime() << reset << endl
    << "Single number " << cyan << "recall" << reset << " time:\t\t" << blue << this->singleNumberRecallTime()
    << reset << endl << endl

    << endl <<"Write something to close summary:" << endl;
    read();
}

template class Numbers<1>;