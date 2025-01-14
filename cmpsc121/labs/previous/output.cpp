// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Your Name>
// Section: <Lab Section>
// Assignment: e.g. Homewrk 01
//

#include <iostream>
using namespace std;

int main()
{
    string first_name;
    cout << "Please enter your first name: ";
    cin >> first_name;
    cout << "Hello there, " << first_name << "!" << endl;
    cout << "Different ways of outputs: " << endl << endl; 
    cout << first_name << "  " << first_name << "  " << first_name;
    cout << endl << endl;
    cout << first_name << "\n";
    cout << first_name << "\n";
    cout << first_name << "\n";
}
/*
Answer 1: It calls the string varriable and stores the users input from the 
terminal in string first_name for further use throughout the program. 
Answer 2: It ends the line where it repeats the users name 3 times in the same line, and then the second endl 
skips the next line so there is a space in between the 2 different types of outputs.

Output:
Hello there, Jack!
Different ways of outputs: 

Jack  Jack  Jack

Jack
Jack
Jack
*/