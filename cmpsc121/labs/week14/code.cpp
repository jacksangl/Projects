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
// Section: <Lab 003L>
// Assignment: Number Game

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

bool guessFn(int random, const int limit);

int main()
{
    // seed random number
    srand((unsigned) time(NULL));
    int upper = 0, random;
    bool correct = false;
    cout << "Enter the upper limit of the guessing number: ";
    cin >> upper;
    // validate user input
    while (upper <= 0)
    {
        cout << "Invalid input, the upper limit must be greater than 0!" << endl;
        cout << "Enter the upper limit of the guessing number: ";
        cin >> upper;
    }
    // get random number
    random = rand() % (upper - 1 + 1) + 1;
    while (!correct)
    {
        correct = guessFn(random, upper);
    }
    return 0;
}

bool guessFn(int random, const int limit)
{
    int guess = 0;
    cout << "Enter your guess between 1 and " << limit << ": ";
    cin >> guess;
    while (guess > limit || guess <= 0)
    {
        cout << "You have entered an invalid number!" << endl;
        cout << "Enter your guess between 1 and " << limit << ": ";
        cin >> guess;
    }
    if (guess < random)
    {
        cout << "Too low, try again." << endl << endl;
        return false;
    }
    else if (guess > random)
    {
        cout << "Too high, try again." << endl << endl;
        return false;
    }
    else{
        cout << "You have chosen the correct number!" << endl;
        return true;
    }
}

/*
Output
Enter the upper limit of the guessing number: 0  
Invalid input, the upper limit must be greater than 0!
Enter the upper limit of the guessing number: 100
Enter your guess between 1 and 100: 101
You have entered an invalid number!
Enter your guess between 1 and 100: 50
Too low, try again.

Enter your guess between 1 and 100: 75
Too high, try again.

Enter your guess between 1 and 100: 62
Too low, try again.

Enter your guess between 1 and 100: 65
Too low, try again.

Enter your guess between 1 and 100: 68
You have chosen the correct number!
*/
