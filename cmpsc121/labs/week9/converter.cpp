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
// Name: <Jack Sangl>
// Section: <003L>
// Assignment: Convert C to F
#include <iostream>
#include <iomanip>

using namespace std;

// function headers
void getTemperature(double[], int size);
void convertTemperature(double[], double[], int size);

// const size
const int SIZE = 4;

int main()
{
    // arrays for temperatures
    // dont need temp[] like the file says
    double c_temp[SIZE];
    double f_temp[SIZE];

    // gets temperatures of user
    getTemperature(c_temp, SIZE);

    // converts temperatures in function
    convertTemperature(c_temp, f_temp, SIZE);

    // prints out temperatures
    for (int i = 0; i < SIZE; i++)
    {
        cout << setprecision(2) << fixed << c_temp[i] << " degrees Celsisus is " << f_temp[i] << " degrees Fahrenheight\n";
    }
}

void getTemperature(double c_temp[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Celsisus temperature " << i + 1 << ": ";
        cin >> c_temp[i];
        while (c_temp[i] < -273.15)
        {
            cout << "The temperature must be greater than -273.15\n";
            cout << "Enter Celsisus temperature " << i + 1 << ": ";
            cin >> c_temp[i];
        }
    }
}

void convertTemperature(double c_temp[], double f_temp[], int size)
{
    for (int i = 0; i < size; i++)
    {
        f_temp[i] = ((9.0 / 5.0) * c_temp[i]) + 32;
    }
}

/*
Output:
Enter Celsisus temperature 1: -274
The temperature must be greater than -273.15
Enter Celsisus temperature 1: -31
Enter Celsisus temperature 2: 0
Enter Celsisus temperature 3: 13.25
Enter Celsisus temperature 4: 100
-31.00 degrees Celsisus is -23.80 degrees Fahrenheight
0.00 degrees Celsisus is 32.00 degrees Fahrenheight
13.25 degrees Celsisus is 55.85 degrees Fahrenheight
100.00 degrees Celsisus is 212.00 degrees Fahrenheight
*/