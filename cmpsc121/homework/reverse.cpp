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
// Assignment: Reverse

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void reverseString(string input, int size);

int main()
{
    string input;
    char again;
    int size = 0;
    while (true)
    {
        cout << "Please enter a string: ";
        getline(cin, input);
        reverseString(input, input.length());
        cout << endl << endl << "Enter another string (Y/N): ";
        cin >> again;
        tolower(again);
        if (again == 'y')
        {
            cin.ignore();
            continue;
        }
        else if (again == 'n')
        {
            return 0;
        }
        else
        {
            while (true)
            {
                cin.clear();
                cout << "Incorrect input!" << endl << "Enter another string (Y/N): ";
                cin >> again;
            }
        }
    }
}

void reverseString(string input, int size)
{
    string copy = input;
    int length = input.length();
    if (size == 0)
    {
    cout << "Your reverse string is: " << endl;
    cout << input; 
    return;
    }
    // recursive case
    else 
    {
        input.replace(length-size, 1, 1, copy[size-1]);
        size -= 1;
        reverseString(input, size);
    }
    // recursive case
}

/*
Output
Please enter a string: Maybe I'll go to the movies.
Your reverse string is: 
.seivom eht otto the movies.

Enter another string (Y/N): y
Please enter a string: However, I think I'll get dinner first!
Your reverse string is: 
!tsrif rennid teg lll get dinner first!

Enter another string (Y/N): n
*/