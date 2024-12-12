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
// Assignment: Coinflip

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;

const double COST = 5.50;
bool coinflip();

int main()
{
    srand((unsigned)time(nullptr));
    bool result;
    double balance = 0, previous = 0, winnings = 0;
    char play;
    int heads = 0, tails = 0, games = 0, flips = 0;

    cout << "Welcome to the Coin Flip Game!" << endl
         << endl;
    cout << "Here's a 100-Flip Example (T = Tails, H = Heads): ";

    for (int i = 0; i < 100; i++)
    {
        result = coinflip();
        if (result)
        {
            heads++;
            cout << "H ";
        }
        else
        {
            tails++;
            cout << "T ";
        }
    }
    cout << endl
         << "There were a total of " << heads << " heads and " << tails << " tails." << endl
         << endl;
    cout << "Each game costs $" << COST << ". We'll flip a coin until the first head appears, on the nth flip." << endl;
    cout << "Your winnings will be $2^(n-2)." << endl;
    cout << "Would you like to play a game (Y/y or N/n)?: ";
    cin >> play;
    play = tolower(play);
    while (true)
    {
        cout << endl;
        while (play != 'y' && play != 'n')
        {
            cin.ignore();
            cin.clear();
            cout << "Please enter Y/y or N/n. " << endl
                 << "Try again: ";
            cin >> play;
            play = tolower(play);
        }
        if (play == 'n')
            break;

        heads = 0;
        tails = 0;
        while (true)
        {
            result = coinflip();
            if (result)
            {
                heads++;
                break;
            }
            else
                tails++;
        }
        previous = balance;
        flips = heads + tails;
        balance = balance + (pow(2.0, flips - 2) - 5.50);
        winnings = pow(2.0, tails - 2);
        cout << setprecision(2) << showpoint << fixed;
        cout << "Game results: " << setw(10) << string(tails, 'T') << 'H' << endl;
        cout << "Prev. Balance: " << setw(10) << previous << endl;
        cout << "Game cost: " << setw(14) << COST << endl;
        cout << "Winnings: " << setw(15) << winnings << endl;
        cout << "New Balance: " << setw(12) << balance << endl
             << endl;
    cout << "Would you like to play a game (Y/y or N/n)?: ";
    cin >> play;
    play = tolower(play);
    }
    cout << "Thanks for playing! Your balance is " << balance << endl;
}

bool coinflip()
{
    int flip = rand() % (2) + 1;
    if (flip == 1)
        return true;
    else
        return false;
}

/*
output

Welcome to the Coin Flip Game!

Here's a 100-Flip Example (T = Tails, H = Heads): H H T T T H H T H T T H T T H T T H T T H H H T H H T H T T T T T H H T T T H H H T T H T H T H T H H T H T H T H H H T T H T H H H T T H H T T H T T H H H T H H T T T H T T H T T T T H T H H H H H T 
There were a total of 49 heads and 51 tails.

Each game costs $5.5. We'll flip a coin until the first head appears, on the nth flip.
Your winnings will be $2^(n-2).
Would you like to play a game (Y/y or N/n)?: g

Please enter Y/y or N/n. 
Try again: y
Game results:           H
Prev. Balance:       0.00
Game cost:           5.50
Winnings:            0.25
New Balance:        -5.00

Would you like to play a game (Y/y or N/n)?: y

Game results:      TTTTTH
Prev. Balance:      -5.00
Game cost:           5.50
Winnings:            8.00
New Balance:         5.50

Would you like to play a game (Y/y or N/n)?: g

Please enter Y/y or N/n. 
Try again: y
Game results:           H
Prev. Balance:       5.50
Game cost:           5.50
Winnings:            0.25
New Balance:         0.50

Would you like to play a game (Y/y or N/n)?: y

Game results:           H
Prev. Balance:       0.50
Game cost:           5.50
Winnings:            0.25
New Balance:        -4.50

Would you like to play a game (Y/y or N/n)?: n


Thanks for playing! Your balance is -4.50
*/