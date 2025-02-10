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
// Assignment: Time
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time {
    public:

        // Constructors
        Time();
        Time(unsigned hours, unsigned minutes, char am_pm);

        // Functions to get the values of member
        unsigned getHours(); // Return the hour number
        unsigned getMinutes(); // Return the minute number
        char getAMorPM(); // Return the AM PM value

        // Set, Display as discussed in class
        void Set(unsigned hours, unsigned minutes, char am_pm);//Set the time
        void Display();                                        //Display the time

        // A convenient forward function 
        void Forward(int minutes); //Forward the time

        // my functions 
        Time operator+(int minutes);
        void operator=(string time);
        void operator+=(int minutes);



    private:
        unsigned myHours, myMinutes;
        char myAMorPM;
};