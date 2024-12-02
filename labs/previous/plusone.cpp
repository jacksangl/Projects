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
// Assignment: Dome Lab Assignment Bonus

//M_PI is a cmath library pi

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

const double PI = 3.14159;
int main()
{
    //defining integers
    float radius, height, volume, radius_cubed, radius_squared, new_volume, new_radius, radius_squared2, radius_cubed2, new_height, calculation;
    cout << "Enter the radius of a dome: ";
    cin >> radius;
    cout << "Enter the height of a dome: ";
    cin >> height;
    //getting values for radius and height

    //calculating the raidus cubed and squared
    radius_cubed = pow(radius, 3);
    radius_squared = pow(radius, 2);
    //calculate volume
    volume = (2.0/3*PI*radius_cubed) + (PI*radius_squared*height);
    //display volume
    cout << "The volume of the dome: " << volume << endl;
    cout << endl;
    
    //defining new radius and heights
    new_radius = radius + 1;
    new_height = height + 1;
    //defining squared radius and cubed
    radius_squared2 = pow(new_radius, 2);
    radius_cubed2 = pow(new_radius, 3);

    new_volume = (2.0/3*PI*radius_cubed2) + (PI*radius_squared2*new_height);
    calculation = new_volume - volume;

    cout << "The volume of the new dome: " << new_volume << endl;
    cout << "The new dome has " << calculation << " more volume than the old dome." << endl;

}

/*
Enter the radius of a dome: 3
Enter the height of a dome: 8
The volume of the dome: 282.743

The volume of the new dome: 586.431
The new dome has 303.687 more volume than the old dome.
*/
