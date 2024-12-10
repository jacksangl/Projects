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
// Assignment: Palindrome

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string &input, int first=0, int last=0);

int main()
{
    string input;
    char again;
    bool result;
    int first = 0, last = 0;
    while (true)
    {
        cout << "Please enter a string: ";
        getline(cin, input);
        last = last = input.length();
        result = isPalindrome(input, first, last);
        if (result)
            cout << "\"" << input << "\" is a Palindrome!";
        else
            cout << "\"" << input << "\" is not Palindrome.";
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

bool isPalindrome(const string &input, int first, int last)
{
    string copy = input;
    // base case
    if (first == last || first > last)
    {
    return true;
    }
    // recursive case
    else 
    {
        cout << "Checking: ";
        for (int i = first; i <= last; i++)
            cout << copy[i];
        cout << endl;
        if (isalpha(input[first]) && isalpha(input[last]))
        {
            tolower(copy[first]);
            tolower(copy[last]);
            if (copy[first] == copy[last])
            {
                last --;
                first ++;
                bool okay = isPalindrome(input, first, last);
                if(okay)
                    {
                        return true;
                    }
                else
                    return false;
            }
            else
                return false;
        }
        else if (isalpha(input[first]))
        {
            cout << "Skipping: \'" << input[last] << "\'" << endl;
            last --; 
            bool okay = isPalindrome(input, first, last);
            if(okay)
            {
                return true;
            }
            else
                return false;
        }
        else if (isalpha(input[last]))
        {
            cout << "Skipping: \'" << input[first] << "\'" << endl;
            first ++;
            bool okay = isPalindrome(input, first, last);
            if(okay)
            {
                return true;
            }
            else
                return false;
        }
        else 
            return false;
    }
    return false;
}


