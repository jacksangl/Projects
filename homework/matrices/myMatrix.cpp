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
// Assignment: Matrix
#include <iostream>
#include <iomanip>
#include "myMatrix.h"

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// Functions that are already implemented by myself. Do not modify.
///////////////////////////////////////////////////////////////////////////////

void myMatrix::PrintMatrix(ostream& out) {
	int index = 0;
	for (unsigned i = 0; i < this->height; i++) {
		for (unsigned j = 0; j < this->width; j++) {
			out << setw(6) << this->myArrayPtr[index];
			index++;
		}
		out << endl;
	}
}

ostream& operator<<(ostream& out, myMatrix& matrix){
	matrix.PrintMatrix(out);
	return out;
}

unsigned myMatrix::GetHeight() {
	return this->height;
}

unsigned myMatrix::GetWidth() {
	return this->width;
}


void myMatrix::SetEntry(unsigned i, unsigned j, int valueToSet) {
	this->myArrayPtr[(i * this->width) + j] = valueToSet;
}




///////////////////////////////////////////////////////////////////////////////
// Implement required member functions below
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Implement the overloading function for += below
///////////////////////////////////////////////////////////////////////////////

// Code for += overloading

///////////////////////////////////////////////////////////////////////////////
// Implement the "big three" below
///////////////////////////////////////////////////////////////////////////////

// Add your "big three" implementation...

int* myMatrix::getPtr() {
	return this->myArrayPtr;
}
myMatrix::myMatrix() {
	myArrayPtr = new int [1];
	height = 1;
	width = 1;
}


myMatrix::myMatrix(unsigned heightVal, unsigned WidthVal, int * sourceArray) {
	myArrayPtr = new int [heightVal*WidthVal];
	height = heightVal;
	width = WidthVal;
	for (int i = 0; i < width*height; i++) {
		myArrayPtr[i] = sourceArray[i];
	}
}

void myMatrix::Concatenate(myMatrix & matrixToConcatenate) {
	unsigned other = matrixToConcatenate.GetHeight();
	if (this->height != other)
		return;
	other = matrixToConcatenate.GetWidth();
	unsigned total = (this->width+other)*height;
	int *ptr = new int [total];
	int *ptr2 = matrixToConcatenate.getPtr();
	int count = 0;
	for (int i = 0, j = 0, k=0; i < total; i++) {
		if (count < width) {
			ptr[i] = myArrayPtr[k];
			k++;
			count++;
		}
		else if (count < width+other) {
			ptr[i] = ptr2[j];
			j++;
			count++;
		}
		else {
			count = 0;
			i--;
		}
	}

	width = width + other;
	delete [] myArrayPtr;
	myArrayPtr = ptr;
	return;
}

void myMatrix::operator+=(myMatrix & matrixToAdd) {
	unsigned other_h= matrixToAdd.GetHeight(), other_w = matrixToAdd.GetWidth();

	if ((other_h!= this->height) || other_w != this->width)
		return;

	int *ptr = matrixToAdd.getPtr();

	for (int i = 0; i < height*width; i++) {
		myArrayPtr[i] += ptr[i];
	}
	return;
}

myMatrix::~myMatrix() {
	delete [] myArrayPtr;
} 

myMatrix::myMatrix(myMatrix &original) {
	height = original.GetHeight(), width = original.GetWidth();
	myArrayPtr = new int [height*width];
	
	for (int i = 0; i < height*width; i++){
		myArrayPtr[i] = original.myArrayPtr[i];
	}
}

myMatrix & myMatrix::operator=(myMatrix & original) {
	height = original.GetHeight(), width = original.GetWidth();
	myArrayPtr = new int [height*width];
	int * ptr = original.getPtr();
	for (int i = 0; i < height*width; i++) 
		myArrayPtr[i] = ptr[i];
	
	return *this;
}

/*
The following shows a matrix created using the default constructor: 

     0


The following shows a matrix created using the second constructor: 

     2     3     4     5     6
     3     4     5     6     2
     1     3     5     7     9
     2     4     6     8    10


Trying to concatenate two matrices. Matrix A: 

     2     3     4     5     6
     3     4     5     6     2
     1     3     5     7     9
     2     4     6     8    10


Matrix B: 

     0     1
     1     0
     1     1
     0     0


After concatenating B to the right of A. A becomes: 

     2     3     4     5     6     0     1
     3     4     5     6     2     1     0
     1     3     5     7     9     1     1
     2     4     6     8    10     0     0


Testing the copy constructor.
The following shows a Matrix C, created from copying the Matrix B above: 

     0     1
     1     0
     1     1
     0     0


Now, we make some changes to matrix C. It becomes: 

     0     5
     1     0
     4     1
     0     0


We print matrix B in the following. Note if the implementation is correct,
changing matrix C should not affact matrix B!

     0     1
     1     0
     1     1
     0     0


Testing the assignment operator.
The following shows a Matrix D, which is assigned with the Matrix B above: 

     0     1
     1     0
     1     1
     0     0


Now, we make some changes to matrix D. It becomes: 

     0     1
     1    10
     1     1
    28     0


We print matrix B in the following. Note if the implementation is correct,
changing matrix D should not affact matrix B!

     0     1
     1     0
     1     1
     0     0


Adding matrix D to matrix B using the += operator.
After this, the matrix B becomes:
     0     2
     2    10
The following shows a matrix created using the default constructor: 

     0


The following shows a matrix created using the second constructor: 

     2     3     4     5     6
     3     4     5     6     2
     1     3     5     7     9
     2     4     6     8    10


Trying to concatenate two matrices. Matrix A: 

     2     3     4     5     6
     3     4     5     6     2
     1     3     5     7     9
     2     4     6     8    10


Matrix B: 

     0     1
     1     0
     1     1
     0     0


After concatenating B to the right of A. A becomes: 

     2     3     4     5     6     0     1
     3     4     5     6     2     1     0
     1     3     5     7     9     1     1
     2     4     6     8    10     0     0


Testing the copy constructor.
The following shows a Matrix C, created from copying the Matrix B above: 

     0     1
     1     0
     1     1
     0     0


Now, we make some changes to matrix C. It becomes: 

     0     5
     1     0
     4     1
     0     0


We print matrix B in the following. Note if the implementation is correct,
changing matrix C should not affact matrix B!

     0     1
     1     0
     1     1
     0     0


Testing the assignment operator.
The following shows a Matrix D, which is assigned with the Matrix B above: 

     0     1
     1     0
     1     1
     0     0


Now, we make some changes to matrix D. It becomes: 

     0     1
     1    10
     1     1
    28     0


We print matrix B in the following. Note if the implementation is correct,
changing matrix D should not affact matrix B!

     0     1
     1     0
     1     1
     0     0


Adding matrix D to matrix B using the += operator.
After this, the matrix B becomes:
     0     2
     2    10
     2     2
    28     0


Testing compatibility issue using += operator
Matrix A dimension: 4 x 7 and Matrix B dimension: 4 x 2
Perform A += B and failed!
Matrix A remains the same after the failed operation
     2     3     4     5     6     0     1
     3     4     5     6     2     1     0
     1     3     5     7     9     1     1
     2     4     6     8    10     0     0
*/