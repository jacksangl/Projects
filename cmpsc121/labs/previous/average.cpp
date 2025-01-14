/* Academic Integrity Affidavit:
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
// Section: <003L>
// Assignment: average.cpp
//
*/

#include <iostream>
using namespace std;
int main()
{
    double number1;
    double number2; 
    double number3; 
    double number4; 
    double number5;
    double sum;
    double average;
    cout << "Please enter number 1: ";
    cin >> number1;
    cout << "Please enter number 2: ";
    cin >> number2;
    cout << "Please enter number 3: ";
    cin >> number3;
    cout << "Please enter number 4: ";
    cin >> number4;
    cout << "Please enter number 5: ";
    cin >> number5;
    sum = number1 + number2 + number3 + number4 + number5;
    cout << endl;
    cout << "The sum of the 5 numbers = " << sum << endl;
    average = sum / 5;
    cout << "The average of the 5 numbers = " << average << endl;

}
/*
Please enter number 1: 28
Please enter number 2: 32
Please enter number 3: 37
Please enter number 4: 24
Please enter number 5: 33

The sum of the 5 numbers = 154
The average of the 5 numbers = 30.8
*/