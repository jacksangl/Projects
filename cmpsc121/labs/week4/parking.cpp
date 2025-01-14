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
// Assignment: Parking Rate





#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>

int main()
{
    char vehicle;
    int vehicleType;
    float hours = 0;
    float firstRate = 0;
    float secondRate = 0;
    float total = 0;
    float buffer = 0;

    //prompt user for vehicle type
    std::string license;
    std::string dummy;
    std:: cout << "Enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): ";
    std::cin>> vehicle;
    if (vehicle != 'c' && vehicle != 'C' && vehicle != 't' && vehicle != 'T' && vehicle != 'b' && vehicle != 'B')
    {
        std::cout << "That is an invalid vehicle type\n";
        return 1;
    }

    //prompt user for hours parked and round up
    std::cout<< "Enter the number of hours parked: ";
    std::cin>> hours;
    hours = ceil(hours);
    
    //prompt user for license plate
    std::cout<< "What is the license plate? ";
    getline(std::cin, dummy);
    getline(std::cin, license);
    std::cout<< "\n";
    
    //figure out vehicle type and rates
    if (vehicle == 'C' || vehicle == 'c')
    {
        vehicleType = 1;
        std::cout<< "Vehicle Type: Car\n";
        firstRate = 1.25;
        secondRate = 1.50;
    }
    else if (vehicle == 't' || vehicle == 'T')
    {
        vehicleType = 2;
        std::cout<< "Vehicle Type: Truck\n";
        firstRate = 2.75;
        secondRate = 3.75;
    }
    else 
    {
        vehicleType = 3;
        std::cout<< "Vehicle Type: Bus\n";
        firstRate = 9.50;
        secondRate = 6.75;
    }
    if (vehicleType == 1 || vehicleType == 2)
    {
        if (hours >= 2)
        {
            total = firstRate * 2;
            hours -= 2;
            buffer = hours * secondRate;
            total +=buffer;
            hours += 2;
        }
        else
        {
            total = hours * firstRate;
        }
    }
    else
    {
    if (hours >= 1)
        {
            total = firstRate;
            hours -= 1;
            buffer = hours * secondRate;
            total +=buffer;
            hours += 1;
        }
        else
        {
            total = firstRate;
        }
    }


    //give final outputs
    std::cout<< "Time: " <<hours << " hours\n";
    std::cout << "License Plate: " << license << "\n";
    std:: cout << std:: fixed << std:: setprecision(2) << std:: showpoint;
    std::cout << "Amount Due ($): " << total << "\n";

}
/*
Output 1
Enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): X
That is an invalid vehicle type
*/
/*
Output 2
Enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): C
Enter the number of hours parked: 4.0
What is the license plate? ABC 123

Vehicle Type: Car
Time: 4 hours
License Plate: ABC 123
Amount Due ($): 5.50
*/
/*
Output 3
Enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): T
Enter the number of hours parked: 9.4
What is the license plate? JCD 8678

Vehicle Type: Truck
Time: 10 hours
License Plate: JCD 8678
Amount Due ($): 35.50
*/
/*
Output 4
Enter the vehicle type ('C' for car, 'T' for truck, 'B' for bus): B
Enter the number of hours parked: 2.7
What is the license plate? SBS 4556

Vehicle Type: Bus
Time: 3 hours
License Plate: SBS 4556
Amount Due ($): 23.00
*/

