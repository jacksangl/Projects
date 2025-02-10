//
// Name: skeleton template for overloading operators  
//
// One Complex object holds one Complex number

#include "Complex2.h"

//------------------------------ Complex ------------------------------------
// default constructor:  parameters are real and imaginary parts respectively
Complex::Complex(double re, double im)
{
   this->re = re;
   this->im = im;
}

//(a)------------------------------- add -------------------------------------
// overloaded +: addition of 2 complex numbers, current object and parameter


//(b)------------------------------ subtract ---------------------------------
// overloaded -: subtract 2 complex numbers, current object and parameter


//(c)------------------------------ multiply ---------------------------------
// overloaded *: multiply 2 complex numbers, current object and parameter


//(d)-------------------------------- divide ---------------------------------
// overloaded /: divide 2 complex numbers, current object and parameter
// check division by zero condition


//(e)-------------------------------- equal ----------------------------------
// overloaded ==: equal comparison of current Complex object and parameter


//(f)------------------------------- not equal -------------------------------
// overloaded !=: not equal comparison of current Complex object and parameter



//(g)-------------------------------- print-----------------------------------
// overloaded print()



//(h)--------------------------------- << -------------------------------------
// overloaded << (output operator)
ostream & operator<<(ostream & os, Complex & z)
{
    
}


