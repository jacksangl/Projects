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
// Assignment: rectangle

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct rectangle
{
    double length;
    double width;
    double area;
};

void mult(double &a, double &b);

int main()
{
    rectangle r;

    // get user starting length
    cout << "Enter the starting length: ";
    cin >> r.length;
    while (r.length <= 0)
        {
            // clears cin incase of faulty input
            cin.ignore();
            cin.clear();
            cout << "Please enter length greater than zero!" << endl;
            cout << "Enter the starting length: ";
            cin >> r.length;
        }

    // get starting width
    cout << "Enter the starting width: ";
    cin >> r.width;
    while (r.width <= 0)
        {
            // clears cin incase of faulty input
            cin.ignore();
            cin.clear();
            cout << "Please enter width greater than zero!" << endl;
            cout << "Enter the starting width: ";
            cin >> r.width;
        }
    
    r.area = r.width*r.length;
    cout << showpoint << setprecision(2) << fixed;
    // do multiplication and output while area < 500
    do
    {
        cout << r.length << " x " << r.width << " = " << r.area << endl;
        mult(r.length, r.width);
        r.area = r.length*r.width;

    }
    while (r.area <= 500);
    cout << "DONE" << endl;
    return 0;
}

void mult(double &a, double &b)
{
    a *= 2;
    b *= 2;
}

/*
Enter the starting length: -20
Please enter length greater than zero!
Enter the starting length: 15.75
Enter the starting width: 0
Please enter width greater than zero!
Enter the starting width: 1.2
15.75 x 1.20 = 18.90
31.50 x 2.40 = 75.60
63.00 x 4.80 = 302.40
DONE
*/