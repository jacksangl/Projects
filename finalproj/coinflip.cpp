
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
