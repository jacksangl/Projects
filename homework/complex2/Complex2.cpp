//
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


