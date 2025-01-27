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
// Assignment: 
#include <cstring>
#include <iostream>

int* append(int*, int, int*, int);
int* merge(int*, int, int*, int);
void print(int*, int, const char *); 
using namespace std;

int main()
{
    int arrayA[] = {11, 33, 55, 77, 99}; // use other values for more tests
    int arrayB[] = {22, 44, 66, 88};
    print(arrayA, 5, "Sorted array A: ");
    print(arrayB, 4, "Sorted array B: ");
    int *arrayC = append(arrayA, 5, arrayB, 4); // arrayC points to the appended array
    print(arrayC, 9, "Append B to A: ");
    int *arrayD = merge(arrayA, 5, arrayB, 4);
    print(arrayD, 9, "Merge A to B: ");
    delete[] arrayC;
    delete[] arrayD;

    return 0;
}
int *append(int *arrayA, int sizeA, int *arrayB, int sizeB)
{
    int newsize = sizeA+sizeB, check = newsize-sizeA;
    int *arrayC = new int [newsize];
    int counter = sizeA;
    for (int i = 0; i < sizeA; i++) {
        arrayC[i] = arrayA[i];
    }
    for (int j = counter, i = 0; j < newsize;i++, j++) {
        arrayC[j] = arrayB[i];
    }
    return arrayC;
}
int *merge(int *arrayA, int sizeA, int *arrayB, int sizeB)
{
    int newsize = sizeA+sizeB, check = newsize-sizeA;
    int *arrayD = new int [newsize];
    int *ptr = arrayA, *ptr2 = arrayB;
    int counter =0, lower, higher, check1= 0, check2 =0;

    for (int i = 0; i < newsize; i++) {
        if (check1 < sizeA)
            *ptr = arrayA[check1];
        else
            *ptr = arrayB[check2];
        if (check2 < sizeB)
            *ptr2= arrayB[check2];
        else
            *ptr2 = arrayA[check1];
        if( *ptr < *ptr2) {
            arrayD[counter] = *ptr;
            check1++;
            counter++;
        }
        else {
            arrayD[counter] = *ptr2;
            check2++;
            counter++;
        }
    }
return arrayD;
}
void print(int *array, int size, const char *lable)
{
    cout << lable << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


