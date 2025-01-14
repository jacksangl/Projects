#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <ctime>
#include <random>
using namespace std;

int main()
{
    int objects, minimum = 2, player1, player2, rule;
    bool first = false;
    bool winner = false;
    char yes;

    srand(time(nullptr));

    cout << "Would you like to go first (y for yes and other input for no)? ";
    cin >> yes;
    cout << "Enter the inital number of objects: ";
    cin >> objects;
    yes = tolower(yes);
    if (yes == 'y')
        first = true;
    rule = objects - 1;
    if (first)
    {
        while (objects > 0)
        {
            cout << "Its your turn. Enter the number of objects to remove (" << minimum << "-" << rule << "): ";
            cin >> player1;
            while (player1 > rule || player1 < minimum)
            {
                cout << "Invalid move. Enter the number of objects to remove (" << minimum << "-" << rule << "): ";
                cin >> player1;
            }
            objects = objects - player1;
            cout << "Move accepted. The number of objects remaining: " << objects << endl;
            if (objects == 0)
            {
                winner = true;
                break;
            }
            if (objects == 1)
            {
                winner = false;
                cout << "Its the computers turn. The computer removes 1 object.\nThe number of objects remaining: 0" << endl;
                break;
            }

            minimum = 1;

            rule = player1 * 2;
            if (rule > objects)
                rule = objects;
            if (rule >= minimum)
            {
                player2 = minimum + rand() % (rule - minimum + 1);
            }
            else
            {
                player2 = minimum; 
            }
            cout << rule << endl;
            player2 = minimum + (rand() % (rule - minimum) + 1);
            objects = objects - player2;
            cout << "Its the computers turn. The computer removes " << player2 << " objects.\nThe number of objects remaining: " << objects << endl;
            rule = player2 * 2;
            if (rule > objects)
                rule = objects;
            if (objects == 0)
                winner = false;
        }
    }

    else
    {
        while (objects > 0)
        {
            if (rule >= minimum)
            {
                player2 = minimum + rand() % (rule - minimum + 1);
            }
            else
            {
                player2 = minimum;
            }
            objects = objects - player2;
            cout << "Its the computers turn. The computer removes " << player2 << " objects.\nThe number of objects remaining: " << objects << endl;
            if (objects == 0)
            {
                winner = false;
                break;
            }
            minimum = 1;
            rule = player2 * 2;
            if (rule > objects)
                rule = objects;
            cout << "Its your turn. Enter the number of objects to remove (" << minimum << "-" << rule << "): ";
            cin >> player1;
            while (player1 > rule || player1 < minimum)
            {
                cout << "Invalid move. Enter the number of objects to remove (" << minimum << "-" << rule - 1 << "): ";
                cin >> player1;
            }

            objects = objects - player1;
            cout << "Move accepted. The number of objects remaing: " << objects << endl;
            rule = player1 * 2;
            if (rule > objects)
                rule = objects;
            if (objects == 0)
                winner = true;
        }
    }

    if (winner == true)
        cout << "You win!\n";
    else
        cout << "The computer wins!\n";
}
/*
Output 1
Would you like to go first (y for yes and other input for no)? y
Enter the inital number of objects: 50
Its your turn. Enter the number of objects to remove (2-49): 20
Move accepted. The number of objects remaining: 30
30
Its the computers turn. The computer removes 16 objects.
The number of objects remaining: 14
Its your turn. Enter the number of objects to remove (1-14): 13
Move accepted. The number of objects remaining: 1
Its the computers turn. The computer removes 1 object.
The number of objects remaining: 0
The computer wins!

Output 2
Would you like to go first (y for yes and other input for no)? n
Enter the inital number of objects: 100
Its the computers turn. The computer removes 24 objects.
The number of objects remaining: 76
Its your turn. Enter the number of objects to remove (1-48): 34
Move accepted. The number of objects remaing: 42
Its the computers turn. The computer removes 35 objects.
The number of objects remaining: 7
Its your turn. Enter the number of objects to remove (1-7): 7
Move accepted. The number of objects remaing: 0
You win!
*/