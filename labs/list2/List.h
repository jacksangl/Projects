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

using namespace std;

typedef int ElementType; // Now "ElementType" is "int"
                         //can change int to double,char,...
class List {
  public:
    List(int maxSize = 1024);  //constructor

    List(ElementType * array, int arraySize, int capacity);// my constructor
    List(List& orig, int lowIndex, int highIndex);
    void Append(List& listToAppend);

    void ExpandCapacity(int sizeToExpand);
    void TryShrink();
    //Big Three:
    ~List(); // Destructor
    List(const List & orig); // Copy Constructor
    List & operator= (const List & orig); // Assignment operator

    unsigned size() const;
    bool empty() const; //check if empty
    void insert(ElementType item, int pos); //insertion
    void erase(int pos);	//deletion
    void display(ostream & out) const; //display every item
    ElementType get(unsigned pos) const;
    int getCapacity();
  private:
    int mySize;       // current # of items in list     
    int myCapacity;
    ElementType * myArrayPtr; //pointer to dynamic array
};

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