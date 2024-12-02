// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Jack Sangl>
// Section: <003L>
// Assignment: scores.cpp

#include <iostream>
#include <cstdlib>
#include <iomanip>

// function headers 
void getScores(double *scores, int size);
void sortScores(double *scores, int size);
double computeAverage(double *scores, int size);

using namespace std;

int main()
{
    // declare variables
    double *scores = nullptr, average = 0;
    int size = 0;
    cout << "Enter the number of scores: ";
    cin >> size;


    // validate user input
    while (size <= 1)
    {
        if (cin.fail())
        {
            // used help from google and prof to fix entering in 
            cout << "FAILED\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard remaining input
            cout << "Enter the number of scores: ";
            cin >> size;
        }
        else 
        {
            cout << "Please enter the number of scores to be greater than 1, try again.\n";
            cout << "Enter the number of scores: ";
            cin >> size;
        }
    }
    
    // dynamically allocate memory to an a array sizeof the user input
    scores = new double[size];

    // get user scores
    getScores(scores, size);
    // sort scores
    sortScores(scores, size);
    
    cout << "\n" << "The test scores are in ascending order: \n";
    // display scores
    cout << showpoint << setprecision(2) << fixed;
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << "\n";
    }

    // calculate average 
    average = computeAverage(scores, size);

    // display average
    cout << "\n" << "The average score is " << average << "\n";

    //remove memory
    delete [] scores;
}

void getScores(double *scores, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter test score " << i + 1 << ": ";
        cin >> scores[i];
        while (scores[i] < 0)
        {
            cin.clear();
            cout << "Not allowed to enter a negative value! Try again.\n";
            cout << "Enter test score " << i + 1 << ": ";
            cin >> scores[i];
        }
    }
    return;
}

void sortScores(double *scores, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (scores[j] > scores[j+1])
            {
                swap(scores[j], scores[j+1]);
            }
        }
    }
    return;
}

double computeAverage(double *scores, int size)
{
    double average = 0;
    for (int i = 0; i < size; i++)
    {
        average += scores[i];
    }
    average = average / size;
    return average;
}

/*
Output: 
Enter the number of scores: 1
Please enter the number of scores to be greater than 1, try again.
Enter the number of scores: 5
Enter test score 1: 85.5
Enter test score 2: -20
Not allowed to enter a negative value! Try again.
Enter test score 2: 99
Enter test score 3: 53.8
Enter test score 4: 78.2
Enter test score 5: 89

The test scores are in ascending order: 
53.80
78.20
85.50
89.00
99.00

The average score is 81.10
*/