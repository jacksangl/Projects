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
// Assignment: dice
#include <iostream>
#include "dice.h"
#include <iomanip>
using namespace std;

double tosser(Dice d[], int dice_ammount);

const int SIZE = 3, TOSS_AMMOUNT = 1000000;

int main()
{
    srand(time(NULL));
    Dice dices[SIZE];
    int counter = 0, dice1 = 0, dice2 = 0, dice3 = 0, tosses = 0;
    double probability = 0, outcome = 0;
    cout << "The inital face up numbers are: " << dices[0].getSideUp() << " " << dices[1].getSideUp() << " " << dices[2].getSideUp() << endl;
    // not done
    cout << showpoint << setprecision(5);
    cout << "The theoretical probability of 3 dice tosses with the same number = " << 1.0 * 1.0 / 6.0 * 1.0 / 6.0 << endl;

    // gives first experimental output
    for (int i = 0; i < TOSS_AMMOUNT; i++)
    {
        dices[0].toss();
        dices[1].toss();
        dices[2].toss();
        dice1 = dices[0].getSideUp();
        dice2 = dices[1].getSideUp();
        dice3 = dices[2].getSideUp();
        if (dice1 == dice2 && dice2 == dice3)
        {
            counter++;
        }
    }
    probability = double(counter) / TOSS_AMMOUNT;
    counter = 0;
    cout << "The experimental probability of 3 dice tosses with the same number = " << probability << endl
         << endl;
    while (true)
    {
        cout << "Please enter a number (3-18) for the sum of 3 dice tosses\nEnter 0 to stop the experiment: ";
        cin >> tosses;
        if (tosses == 0)
        {
            break;
        }
        while (tosses < 3 || tosses > 18)
        {
            // clears cin incase of faulty input
            cin.ignore();
            cin.clear();
            cout << "Invalid outcome value! Try again." << endl;
            cout << "Please enter a number (3-18) for the sum of 3 dice tosses\nEnter 0 to stop the experiment: ";
            cin >> tosses;
        }

        probability = tosser(dices, tosses);
        cout << "The experimental probability of 3 dice tosses with an outcome of " << tosses << " = " << probability << endl
             << endl;
    }
    cout << "Outcome   Probability   Outcome Count   Distribution Histogram" << endl;
    cout << "=======   ===========   =============   ======================" << endl;
    cout << setprecision(7) << fixed;
    for (int i = 0; i <= 15; i++)
        {
            probability = tosser(dices, i+3);
            cout << setprecision(7) << fixed;
            cout << setw(7) << right << i+3 << setw(14) << probability;
            outcome = round(probability*215);
            cout << setprecision(0) << noshowpoint << setw(11) << outcome << setw(9); 
            for (int j = 0; j < outcome; j++)
            {
                cout << '*';
            }
            cout << endl; 
        }
}
double tosser(Dice d[], int toss_num)
{
    int counter = 0;
    int dice1 = 0, dice2 = 0, dice3 = 0, sum = 0;
    for (int i = 0; i < TOSS_AMMOUNT; i++)
    {
        d[0].toss();
        d[1].toss();
        d[2].toss();
        dice1 = d[0].getSideUp();
        dice2 = d[1].getSideUp();
        dice3 = d[2].getSideUp();
        sum = dice1 + dice2 + dice3;
        if (sum == toss_num)
        {
            counter++;
        }
    }
    return double(counter) / TOSS_AMMOUNT;
}

/*
output
The inital face up numbers are: 1 1 2
The theoretical probability of 3 dice tosses with the same number = 0.027778
The experimental probability of 3 dice tosses with the same number = 0.027648

Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 3
The experimental probability of 3 dice tosses with an outcome of 3 = 0.0045630

Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 2
Invalid outcome value! Try again.
Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 19
Invalid outcome value! Try again.
Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 5
The experimental probability of 3 dice tosses with an outcome of 5 = 0.027578

Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 9
The experimental probability of 3 dice tosses with an outcome of 9 = 0.11505

Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to stop the experiment: 0
Outcome   Probability   Outcome Count   Distribution Histogram
=======   ===========   =============   ======================
      3     0.0046240          1        *
      4     0.0139700          3        ***
      5     0.0274420          6        ******
      6     0.0463010         10        **********
      7     0.0699300         15        ***************
      8     0.0972360         21        *********************
      9     0.1158080         25        *************************
     10     0.1252350         27        ***************************
     11     0.1250070         27        ***************************
     12     0.1159120         25        *************************
     13     0.0976290         21        *********************
     14     0.0700660         15        ***************
     15     0.0462400         10        **********
     16     0.0273960          6        ******
     17     0.0139410          3        ***
     18     0.0046360          1        *
*/

