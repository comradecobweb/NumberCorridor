#include "numbers.hpp"


///
/// This function is responsible for reading a single number from the user.
/// @param index Position of an element in the array or position of an group in the array.
void Numbers::see(int &index)
{
    using namespace std;
    int answer;

    if (group_size==1)
    {
        while (true)
        {
            clear();
            cout << "Number " << yellow << (index + 1) << reset << "/" << blue << this->length << reset << ":" << endl
                 << endl << "\t" << magenta << this->questions->get(index) << reset << endl << endl;

            if (index != this->length)
            {
                if (index == this->length-1)
                {
                    cout << "Write " << cyan << 1 << reset << " to continue." << endl;
                }
                else
                {
                    cout << "Write " << cyan << 1 << reset << " to see next." << endl;
                }
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
    else
    {
        int * array = this->questions->getGroup(index);

        while (true)
        {
            clear();
            cout << "Group " << yellow << (index + 1) << reset << "/" << blue << this->countGroups() << reset << ":" <<
            endl << endl << magenta;


            for(int i = 0; i < this->getGroupSize(index); ++i)
            {
                cout << array[i] << " ";
            }

            cout << reset << endl << endl;

            if (index != this->length)
            {
                if (index == this->length-1)
                {
                    cout << "Write " << cyan << 1 << reset << " to continue." << endl;
                }
                else
                {
                    cout << "Write " << cyan << 1 << reset << " to see next." << endl;
                }
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
        if (array) free(array);
    }
}

///
/// This function is responsible for reading a single number from the user.
/// @param index Position of an element in the array or position of an group in the array.
/// @throw std::bad_alloc If can't allocate memory for the array.
void Numbers::write(int &index)
{
    using namespace std;
    int answer;


    if (group_size==1)
    {
        while (true)
        {
            clear();
            cout << "Number " << yellow << (index + 1) << reset << "/" << blue << this->length << reset << ":" << endl
                 << endl << "\t";
            answer = read(magenta);

            if (answer <= max-1 && answer > -1)
            {
                if (this->answers->set(index, answer))
                {
                    break;
                }
            }
        }
    }
    else
    {
        const int size = this->getGroupSize(index);
        int *array = (int *)malloc(sizeof(array)*size);
        if (!array) throw std::bad_alloc();

        for (int i = 0; i < size; ++i)
        {
            array[i] = -1;
        }

        for (int i = 0; i < size; ++i)
        {
            while (true)
            {
                clear();
                cout << "Group " << yellow << (index + 1) << reset << "/" << blue << this->countGroups() << reset << ":" <<
                endl << endl << magenta;

                for (int j = 0; j < size; ++j)
                {
                    if (j==i)
                    {
                        cout << reset << green << "_" << reset << magenta;
                    }
                    else
                    {
                        if (array[j]!=-1)
                        {
                            cout << array[j];
                        }
                        else
                        {
                            cout << "*";
                        }

                    }
                }
                cout << reset << endl << endl;
                answer = read(magenta);

                if (answer <= max-1 && answer > -1)
                {
                    array[i] = answer;
                    break;
                }
            }
        }
        this->answers->set(index, array);
        free(array);
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

        if (group_size != 1 && (i+1) % group_size == 0 && i!= this->length-1)
        {
            cout << endl;
        }

    }

    float score = this->getScore(wrong);

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
    this->getSingleNumberMemorizationTime() << reset << endl
    << "Single number " << cyan << "recall" << reset << " time:\t\t" << blue << this->getSingleNumberRecallTime()
    << reset << endl << endl

    << endl <<"Write something to close summary:" << endl;
    read();
}