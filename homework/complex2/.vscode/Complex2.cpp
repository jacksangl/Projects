//
// Name: skeleton template for overloading operators  
//
// One Complex object holds one Complex number

#include "Complex2.h"
#include <cmath> 
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
   c.re = re+z.re;
   c.im = im+z.im;
   return c;
}

//(b)------------------------------ subtract ---------------------------------
// overloaded -: subtract 2 complex numbers, current object and parameter
Complex Complex::operator-(const Complex & z) {
   Complex c;
   c.re = re-z.re;
   c.im = im-z.im;
   return c;
}

//(c)------------------------------ multiply ---------------------------------
// overloaded *: multiply 2 complex numbers, current object and parameter
Complex Complex::operator*(const Complex & z) {
   Complex c;
   c.re =( re*z.re) - (im*z.im);
   c.im =(re*z.im)+(im*z.re);
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
      c.re =(re*z.re+im*z.im) / ((z.re*z.re)+(z.im*z.im));
      c.im =(im*z.re-re*z.im) / ((z.re*z.re)+(z.im*z.im));
   }
   count ++;
   return c;
}

//(e)-------------------------------- equal ----------------------------------
// overloaded ==: equal comparison of current Complex object and parameter
Complex Complex::operator==(const Complex c) {
   if (c.re != re)
      return false;
   if (c.im != im)
      return false;

   return true;
}

//(f)------------------------------- not equal -------------------------------
// overloaded !=: not equal comparison of current Complex object and parameter
ostream & operator<<(ostream & os, Complex & z)
{
   static int count = 0;
   cout << setprecision(2) << fixed << showpoint;
   if (is_parenthesis && im >=0) {
      cout << "(" << re << " + " << im << "i)";
   }
   else if (is_parenthesis && im <=0) {
      cout << "(" << re << " - " << abs(im) << "i)";
   }
   else if (im >=0)
      cout << re << " + " << im << "i";
   else
      cout << re << " - " << abs(im) << "i";


   return;
}


//(g)-------------------------------- print-----------------------------------
// overloaded print()



//(h)--------------------------------- << -------------------------------------
// overloaded << (output operator)
ostream & operator<<(ostream & os, Complex & z)
{
    
}


