//
// Name: key solution header for complex number
// 
// One Complex object holds one Complex number

#ifndef COMPLEX2_H
#define COMPLEX2_H
#include <iostream>
using namespace std;


class Complex {     // complex number class
    public:
        Complex(double re = 0.0, double im = 0.0);   // default constructor
        Complex operator+(const Complex & z);
        Complex operator-(const Complex & z);
        Complex operator*(const Complex & z);
        Complex operator/(const Complex & z);
        bool operator==(const Complex & z);
        bool operator!=(const Complex &z);
        // add the prototypes of required methods here.
        /*      
        ...
       
        */
        double operator%(Complex & z);
        void print(ostream& os);
        friend ostream & operator<<(ostream & os, Complex & z);

    private:
        double re;
        double im;

        // add the private prototypes methods here from
        // previous LabProj4 and add those functions source
        // in this project 
        /*
        ...
        
        */
        // Or you can implement the overloaded operators 
        // by adding the LabProj 4 source code into the them
};
ostream & operator<<(ostream & os, Complex & z); 
// May generate linker issue if the code is implemented here.
// The code should be implemented in .cpp source file

#endif

