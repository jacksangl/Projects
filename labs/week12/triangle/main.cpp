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
// Assignment: triangle

#include <iostream>
#include "triangle.h"
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    Triangle user;
    double height, base, area;
    bool flag;
    do
    {
        cout << "Enter the height of the triangle in meters: ";
        cin >> height;
        flag = user.setheight(height);
        if (flag != true)
        {
            cout << "The height must be greater than 0, please try again." << endl;
        }
    }
    while(flag != true);

    do
    {
        cout << "Enter the base of the triangle in meters: ";
        cin >> base;
        flag = user.setbase(base);
        if (flag != true)
        {
            cout << "The base must be greater than 0, please try again." << endl;
        }
    }
    while(flag != true);

    area = user.getarea();
    cout << showpoint << setprecision(2) << fixed;
    cout << "The area of the triangle is " << area << " m^2" << endl;
    
}

/*
Enter the height of the triangle in meters: -2
The height must be greater than 0, please try again.
Enter the height of the triangle in meters: 2.57
Enter the base of the triangle in meters: 0
The base must be greater than 0, please try again.
Enter the base of the triangle in meters: 4.88
The area of the triangle is 6.27 m^2
*/