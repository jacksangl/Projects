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
// Assignment: complex2
// Name: skeleton template for overloading operators  
//
// One Complex object holds one Complex number

#include "Complex2.h"
#include <iomanip>

//------------------------------ Complex ------------------------------------
// default constructor:  parameters are real and imaginary parts respectively
Complex::Complex(double re, double im)
{
   this->re = re;
   this->im = im;
}

//(a)------------------------------- add -------------------------------------
// overloaded +: addition of 2 complex numbers, current object and parameter
Complex Complex::operator+(const Complex & z) {

   Complex c;
   c.re = this->re + z.re;
   c.im = this->im + z.im;
   return c; 
}

//(b)------------------------------ subtract ---------------------------------
// overloaded -: subtract 2 complex numbers, current object and parameter
Complex Complex::operator-(const Complex & z) {

   Complex c;
   c.re = this->re - z.re;
   c.im = this->im - z.im;
   return c; 
}

//(c)------------------------------ multiply ---------------------------------
// overloaded *: multiply 2 complex numbers, current object and parameter
Complex Complex::operator*(const Complex & z) {

   Complex c;
   c.re = (this->re*z.re) - (this->im*z.im);
   c.im = (this->re*z.im) + (this->im*z.re);
   return c;
}

//(d)-------------------------------- divide ---------------------------------
// overloaded /: divide 2 complex numbers, current object and parameter
// check division by zero condition
Complex Complex::operator/(const Complex & z) {
   Complex c;
   static int count = 0;
   if (z.re == 0 && count == 0)
      cerr<<"DIVIDE BY ZERO ERROR!!!" << endl;
   else if (z.im == 0) 
      cerr<<"DIVIDE BY ZERO ERROR!!!" << endl;
   else {
      c.re =(this->re*z.re+this->im*z.im) / ((z.re*z.re)+(z.im*z.im));
      c.im =(this->im*z.re-this->re*z.im) / ((z.re*z.re)+(z.im*z.im));
   }
   count ++;
   return c;
   /*(ac + bd) / (c2 + d2) + (bc – ad) / (c2 + d2)i*/
}

//(e)-------------------------------- equal ----------------------------------
// overloaded ==: equal comparison of current Complex object and parameter
bool Complex::operator==(const Complex &z)
{
   if (z.re != this->re)
      return false;
   if (z.im != this->im)
      return false;

   return true;

}

//(f)------------------------------- not equal -------------------------------
// overloaded !=: not equal comparison of current Complex object and parameter
bool Complex::operator!=(const Complex &z)
{
   if (z.re == re)
      return false;
   if (z.im == im)
      return false;

   return true;

}


//(g)-------------------------------- print-----------------------------------
// overloaded print()
void Complex::print(ostream& os) {
   static int count = 0;
   os << setprecision(1) << fixed << showpoint;
   if (this->im >=0) {
      os << "(" << re << " + " << im << "i)";
   }
   else
      os << "(" << re << " - " << abs(im) << "i)";

   return;
}


//(h)--------------------------------- << -------------------------------------
// overloaded << (output operator)
ostream & operator<<(ostream & os, Complex & z)
{
   z.print(os);
   return os;
}

/*
(7.0 + 3.0i) + (1.0 - 2.0i) = (8.0 + 1.0i)
(7.0 + 3.0i) - (1.0 - 2.0i) = (6.0 + 5.0i)
(7.0 + 3.0i) * (1.0 - 2.0i) = (13.0 - 11.0i)
(7.0 + 3.0i) / (1.0 - 2.0i) = (0.2 + 3.4i)
(7.0 + 3.0i) / (0.0 + 0.0i) = DIVIDE BY ZERO ERROR!!!
(7.0 + 3.0i) == (7.0 + 3.0i) is equal 
(7.0 + 3.0i) == (1.0 - 2.0i) is not equal
(7.0 + 3.0i) != (7.0 + 3.0i) is false
(7.0 + 3.0i) != (1.0 - 2.0i) is true

(7.0 + 3.0i) + (7.0 + 3.0i) / (1.0 - 2.0i) - (1.0 - 2.0i) * (7.0 + 3.0i) = (-5.8 + 17.4i)
*/


