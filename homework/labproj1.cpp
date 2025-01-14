#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <ctime>
#include <random>
using namespace std;



int main() {
    /*
    def variables with rule variables

    start game

    */
    int objects, minimum = 2, player1, player2, rule;
    bool first = false;
    bool winner = false;
    char yes;

    srand(time(nullptr));

    cout << "Would you like to go first (y for yes and other input for no)?";
    cin >> yes;
    cout << "Enter the inital number of objects: ";
    cin >> objects;
    yes = tolower(yes);
    if (yes == 'y')
        first = true;
    rule = objects - 1;
    if (first) {
        while (objects > 0) {
            cout << "Its your turn. Enter the number of objects to remove (" << minimum << "-" << rule - 1 << "): ";
            cin >> player1;
            while (player1 > rule || player1 < minimum) {
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
            player2 = minimum + rand() % (rule - 1 - minimum) + 1;
            objects = objects - player2;
            cout << "Its the computers turn. The computer removes " << player2 << " objects.\nThe number of objects remaining: " << objects << endl;
            rule = player2 * 2;
            if (objects == 0)
                winner = false;
        }
    }

    else {
        while (objects > 0) {
            player2 = minimum + rand() % (rule - 1 - minimum) + 1;
            objects = objects - player2;
            cout << "Its the computers turn. The computer removes " << player2 << " objects.\nThe number of objects remaining: " << objects << endl;
            rule = player2 * 2;
            objects = objects - player2;
            if (objects == 0) {
                winner = false;
                break;
            }
            minimum = 1;
            rule = player2 * 2;
            cout << "Its your turn. Enter the number of objects to remove (" << minimum << "-" << rule << "): ";
            cin >> player1;
            while (player1 > rule || player1 < minimum) {
                cout << "Invalid move. Enter the number of objects to remove (" << minimum << "-" << rule - 1 << "): ";
                cin >> player1;
            }

            objects = objects - player1;
            cout << "Move accepted. The number of objects remaing: " << objects << endl;
            rule = player1 * 2;
            if (objects == 0)
                winner = true;
        }
    }

    if (winner == true)
        cout << "You win!";
    else
        cout << "The computer wins!";
    }
        
   /*else
        while */ 
