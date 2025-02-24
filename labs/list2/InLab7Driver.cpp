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
#include "List.h"

using namespace std;

int main()
{
    int orig[] = {6,3,5,1,8,4,7,12,54,37,68};
    List list1(orig, 11, 11);
    cout << "list1 created from array: " << endl;
    list1.display(cout);
    cout << endl << endl;

    int orig2[] = {1,5,15,23,3,0,8};
    List list2(orig2, 7, 20);
    cout << "list2 created from array: " << endl;
    list2.display(cout);
    cout << endl << endl;


    List list3(list1, 2, 8);
    cout << "list3 created from list1, from index [2]-[8]: " << endl;
    list3.display(cout);
    cout << endl << endl;

    List list4(list2, 0, 6);
    cout << "list4 created from list2, from index [0]-[6]: " << endl;
    list4.display(cout);
    cout << endl << endl;

    List list5(list2, 3, 3);
    cout << "list5 created from list2, from index [3]-[3]: " << endl;
    list5.display(cout);
    cout << endl << endl;

    list1.Append(list2);
    cout << "Append list2 to list1. Result: " << endl;
    list1.display(cout);
    cout << endl << endl;

    list1.Append(list3);
    cout << "Append another List, list3, to list1. Result: " << endl;
    list1.display(cout);
    cout << endl << endl;

    cout << "The current capacity of list1 is " << list1.getCapacity() << endl; // Should be 42 if correct
}

/*
list1 created from array: 
6 3 5 1 8 4 7 12 54 37 68 

list1 created from array: 
6 3 5 1 8 4 7 12 54 37 68 

list2 created from array: 
1 5 15 23 3 0 8 

list3 created from list1, from index [2]-[8]: 
5 1 8 4 7 12 0 0 0 0 0 

list4 created from list2, from index [0]-[6]: 
1 5 15 23 3 0 0 

list5 created from list2, from index [3]-[3]: 
0 0 0 0 0 0 0 

Append list2 to list1. Result: 
6 3 5 1 8 4 7 12 54 37 68 0 1 5 15 23 3 0 

Append another List, list3, to list1. Result: 
6 3 5 1 8 4 7 12 54 37 68 0 1 5 15 23 3 0 0 5 1 8 4 7 12 0 0 0 0 

The current capacity of list1 is 42
*/