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
// Assignment: Lab Proj 10

#include "timer.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
#include <vector>
using namespace std;

int countPaths(int north, int east);

int main() {
    Timer t;
    char cont;
    int north = 0, east = 0, count = 0;
    while (true) {
        t.start();
        cout <<"How many points north of A is B?" << endl;
        cin >> north;
        cout << "How many points east of A is B?" << endl;
        cin >> east;

        count = countPaths(north, east);
        cout << "There are " << count << " northeast paths between A and B" << endl;
        t.stop();
        t.show();

        cout << endl << "Enter y or Y to continue the next example or any other letter to exit: ";
        cin >> cont;

        if (tolower(cont) != 'y')
            break;
    }
    return 0;
}

int countPaths(int north, int east) {
    if (north == 0 || east == 0) {
        return 1;
    }
    else {
        return countPaths(north-1, east) + countPaths(north, east-1);
    }
    
}

/*
How many points north of A is B?
2
How many points east of A is B?
3
There are 10 northeast paths between A and B
  Process Timer
  -------------------------------
  Elapsed Time: 0.001s

Enter y or Y to continue the next example or any other letter to exit: y
How many points north of A is B?
12
How many points east of A is B?
14
There are 9657700 northeast paths between A and B
  Process Timer
  -------------------------------
  Elapsed Time: 0.069896s

Enter y or Y to continue the next example or any other letter to exit: Y
How many points north of A is B?
16
How many points east of A is B?
16
There are 601080390 northeast paths between A and B
  Process Timer
  -------------------------------
  Elapsed Time: 2.25431s

Enter y or Y to continue the next example or any other letter to exit: n 
*/