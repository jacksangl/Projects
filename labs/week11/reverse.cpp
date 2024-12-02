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
// Assignment: Reverse Palindrome

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

// function headers
bool is_palindrome(string word);
string reverse(string aSentence);

int main()
{
    // declare multiple varriables
    string word, aSentence, dummy, reversed;
    // get user input
    cout << "Please enter a word: ";
    cin >> word;
    // if function returns true palidrome is true
    if (is_palindrome(word))
        cout << "This is a palindrome.\n\n";
    else
        cout << "This is not a palindrome.\n\n";
    // get more user input
    cout << "Please enter a string below:\n";
    getline(cin, dummy);
    getline(cin, aSentence);
    // reverse the first word in the string
    reversed = reverse(aSentence);
    // display output
    cout << "Your modified string:\n" << reversed << endl;
}

bool is_palindrome(string word)
{

    int length = int(word.length());
    // make word non case sensitive
    for (int i = 0, j = length - 1; i < length / 2; i++, j--)
    {
        word[i] = tolower(word[i]);
    }
    string copy = word;
    // do simple swap 
    for (int i = 0, j = length - 1; i < length / 2; i++, j--)
    {
        swap(copy[i], copy[j]);
        if (word[i] == copy[i])
            continue;
        else
            return false;
    }
    return true;

}
string reverse(string aSentence)
{
    int length = int(aSentence.length());
    // reverse characteristic up until the first space
    for (int i = 0; i < length-1; i++)
    {
        if(isupper(aSentence[i]))
            aSentence[i] = tolower(aSentence[i]);

        else if(islower(aSentence[i]))
            aSentence[i] = toupper(aSentence[i]);
        else if (aSentence[i] == ' ')
            break;
        else
            continue;
    }
    return aSentence;
}

/*
Output 1:
Please enter a word: Racecar
This is a palindrome.

Please enter a string below:
Mcgyver premiered in 1985.
Your modified string:
mCGYVER premiered in 1985.
*/

/*
Output 2:
Please enter a word: reverse
This is not a palindrome.

Please enter a string below:
Bedford-Stuyvesant, Brooklyn is called Bed-Stuy.
Your modified string:
bEDFORD-sTUYVESANT, Brooklyn is called Bed-Stuy.
*/