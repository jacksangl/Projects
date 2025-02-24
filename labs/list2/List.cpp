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
// Assignment: List
#include <iostream>
#include <cstdlib>
#include "List.h"

using namespace std;
int DEFAULT_CAP = 20;

void List::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)  exit(1);
    if (pos < 0 || pos > mySize)  return;
    // shift array elements right to make room for item
    for(int i = mySize; i > pos; i--)
        myArrayPtr[i] = myArrayPtr[i - 1];
    // insert item at pos and increase list size  
    myArrayPtr[pos] = item;
    mySize++;  // don't forget this!
}

void List::erase(int pos)
{
    if (pos < 0 || pos >= mySize)  return;
    // shift array elements left
    for(int i = pos; i < mySize-1; i++)
       myArrayPtr[i] = myArrayPtr[i + 1];
    mySize--;  // don't forget this!
}

List::List(int maxSize){
    mySize = 0;
    myCapacity = maxSize;
    myArrayPtr = new ElementType[maxSize];
}

List::~List(){ delete [] myArrayPtr;} 

List::List(const List & origList) { 
    mySize = origList.mySize; 
    myCapacity = origList.myCapacity; 
    myArrayPtr = new ElementType[myCapacity]; 
    for(int i = 0; i < mySize; i++) 
        myArrayPtr[i] = origList.myArrayPtr[i]; 
}

List & List::operator=(const List & origList)
{
   if (this != & origList)    // check for list = list
   {
        delete[] myArrayPtr;
        mySize = origList.mySize;
        myCapacity = origList.myCapacity;

        myArrayPtr = new ElementType[myCapacity];
   //--- Copy origList's array into this new array
        for(int i = 0; i < myCapacity; i++)
            myArrayPtr[i] = origList.myArrayPtr[i];
   }
   return *this;
}


List::List(ElementType* arr, int arrSize, int capacity) {
    myCapacity = (capacity > 0) ? capacity : DEFAULT_CAP;
    mySize = (arrSize > 0) ? arrSize : 0;
    if (mySize > myCapacity) {
        mySize = myCapacity;
    }

    myArrayPtr = new ElementType[myCapacity];

    for (int i = 0; i < mySize; i++) {
        myArrayPtr[i] = arr[i];
    }
}


bool List::empty() const {
    return (mySize == 0);
}

unsigned List::size() const{
  return mySize;
}

ElementType List::get(unsigned pos) const{
  if(pos >= mySize){
    cerr << "Invalid Index." << endl;
    exit(1);
  }
  return myArrayPtr[pos];
}

void List::display(ostream & out) const {
    for(int i = 0; i < mySize; i++){
       out << myArrayPtr[i] << " ";
   }
}

int List::getCapacity(){
  return myCapacity;
}
// Implementation of new member functions below...

List::List(List& orig, int lowIndex, int highIndex) {
    int org_size = orig.mySize;
    // simple check 
    if (lowIndex < 0 || highIndex >= org_size) {
        std::cerr<<"ERROR: SIZE OUT OF SCOPE";
        return;
    }
    myCapacity = orig.myCapacity;
    mySize = highIndex-lowIndex+1;
    myArrayPtr = new int[myCapacity];
    int *ptr = orig.myArrayPtr;

    for (int i = 0; i <= mySize; i++) 
    {
        myArrayPtr[i] = ptr[i+lowIndex];
    }

    return;
  }

void List::Append(List& listToAppend) {
    myCapacity += listToAppend.myCapacity;
    int org_size = this->mySize;
    mySize += listToAppend.mySize;

    // create new array using new capacity. 
    int *ptr = new ElementType[myCapacity];
    for (int i = 1; i <= org_size; i++ ) {
        ptr[i-1] = myArrayPtr[i-1];
    }

    // clear memory so memory doesnt leak
    delete myArrayPtr;
    myArrayPtr = ptr;

    // set to size+1 to get to 
    for (int i = org_size; i <= mySize; i++) {
        myArrayPtr[i] = listToAppend.myArrayPtr[i-org_size];
    }
    return;
}


/*
list1 created from array: 
6 3 5 1 8 4 7 12 54 37 68 

list2 created from array: 
1 5 15 23 3 0 8 

list3 created from list1, from index [2]-[8]: 
5 1 8 4 7 12 54 

list4 created from list2, from index [0]-[6]: 
1 5 15 23 3 0 8 

list5 created from list2, from index [3]-[3]: 
23 

Append list2 to list1. Result: 
6 3 5 1 8 4 7 12 54 37 68 1 5 15 23 3 0 8 

Append another List, list3, to list1. Result: 
6 3 5 1 8 4 7 12 54 37 68 1 5 15 23 3 0 8 5 1 8 4 7 12 54 

The current capacity of list1 is 42
*/
