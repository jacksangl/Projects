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
// Assignment: Weather.cpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// define structure
struct WeatherInfo
{
    double total;
    double lowest;
    double highest;
};
// function prototypes
void displayAverages(WeatherInfo year[], int nQuarter);
void computeMinMax(WeatherInfo year[], int nQuarter, double &highest, double &lowest, int &highQuarter, int &lowQuarter, double &total);

int main()
{
    // declare an array of size 4 to represent a whole year
    WeatherInfo year[4];
    // other variables
    double highest = 0, lowest = 0, total = 0;
    int highQuarter = 0, lowQuarter = 0,  nQuarter = 0;
    int length = sizeof(year) / sizeof(year[0]);

    // prompt user for input
    cout << "Enter the total rainfall, low & high temperatures: \n";
    for (int i = 0; i < length; i++)
    {
        cout << "Quarter " << i+1 << ": ";
        cin >> year[i].total >> year[i].lowest >> year[i].highest; 
        // checks for incorrect input
        while (year[i].lowest > 140 || year[i].lowest < -100 || year[i].highest > 140 || year[i].highest < -100 || year[i].lowest > year[i].highest)
        {
            // clears cin incase of faulty input
            cin.ignore();
            cin.clear();
            cout << "ERROR: Temperature range: -100 through 140" << endl;
            cout << "Low temperature <= high temperature." << endl;
            cout << "Please enter low and high temperatures again: ";
            cin >> year[i].lowest >> year[i].highest;
        }
        
    }
    // initalizing highest and lowest in order to compare
    highest = year[0].highest;
    lowest = year[0].lowest;
    highQuarter = 1;
    lowQuarter = 1;
    // computing the minMax of the 4 quarters
    for (int i = 0; i < length; i++)
    {
        nQuarter = i;
        computeMinMax(year, nQuarter, highest, lowest, highQuarter, lowQuarter, total);
    }

    // display output to user
    cout << "Total Rainfall: " << total << endl;
    displayAverages(year, nQuarter);
    cout << "Highest temperature: " << highest << " (Quarter " << highQuarter<< ")" << endl;
    cout << "Lowest temperature: " << lowest << " (Quarter " << lowQuarter<< ")" << endl;
}


void computeMinMax(WeatherInfo year[], int nQuarter, double &highest, double &lowest, int &highQuarter, int &lowQuarter, double &total)
{
    if (highest < year[nQuarter].highest)
    {
        highest = year[nQuarter].highest;
        highQuarter = nQuarter+1;
    }
    if (lowest > year[nQuarter].lowest)
    {
        lowest = year[nQuarter].lowest;
        lowQuarter = nQuarter+1;
    }
    total += year[nQuarter].total;
}

void displayAverages(WeatherInfo year[], int nQuarter)
{
    double avg_rain = 0, avg_temp = 0;
    // takes the quarter of the functions and adds its values to the running variables
    for (nQuarter = 0; nQuarter < 4; nQuarter++)
    {
        avg_rain += year[nQuarter].total;
        avg_temp += (year[nQuarter].lowest + year[nQuarter].highest);
    }
    // calculates them
    avg_rain = avg_rain / (nQuarter);
    avg_temp = avg_temp / (nQuarter*2);
    // displays output
    cout << showpoint << setprecision(2) << fixed;
    cout << "Average quarterly rain: " << avg_rain << endl;
    cout << "Average quarterly temperature: " << avg_temp << endl;
}

/*
Output: 
Enter the total rainfall, low & high temperatures: 
Quarter 1: 15 40 67
Quarter 2: 40 50 78
Quarter 3: 30 58 80
Quarter 4: 5 -110 85
ERROR: Temperature range: -100 through 140
Low temperature <= high temperature.
Please enter low and high temperatures again: 65 141
ERROR: Temperature range: -100 through 140
Low temperature <= high temperature.
Please enter low and high temperatures again: 140 65
ERROR: Temperature range: -100 through 140
Low temperature <= high temperature.
Please enter low and high temperatures again: 65 85
Total Rainfall: 90
Average quarterly rain: 22.50
Average quarterly temperature: 65.38
Highest temperature: 85.00 (Quarter 4)
Lowest temperature: 40.00 (Quarter 1)
*/