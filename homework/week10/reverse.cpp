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
// Section: <003L>
// Assignment: reverse.cpp

#include <iostream>
#include <cstdlib>
#include <iomanip>

// function declaration
void getNumbers(int *num_array, int array_size);
void reverseArray(int *num_array, int array_size);

using namespace std;
int main()
{
    // declare variable
    int *num_array = nullptr;
    int array_size = 0, average = 0;
    
    // get user input
    cout << "Enter the size of array: ";
    cin >> array_size;
    // validate user input
    while (array_size < 1)
    {
        if (cin.fail())
        {
            // used help from google and prof to fix entering in
            cout << "FAILED\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard remaining input
            cout << "Enter the size of array: ";
            cin >> array_size;
        }
        else
        {
            cout << "The size of array must be greater than 0, try again.\n";
            cout << "Enter the size of array: ";
            cin >> array_size;
        }
    }
    cout << "\n";
    // dynamically allocate memory to an a array sizeof the user input
    num_array = new int[array_size];
    
    // get number for array
    getNumbers(num_array, array_size);
    
    //display original array
    cout << "\nThe contents of the orignal array are: [";
    for (int i = 0; i < array_size; i++)
    {
        cout << num_array[i] << ", ";
    }

    // reverse the array and display its contents
    cout << "\b\b]\nThe contents of the reversed array are: [";
    reverseArray(num_array, array_size);
    for (int i = 0; i < array_size; i++)
    {
        cout << num_array[i] << ", ";
    } 
    cout << "\b\b]\n";

    // free dynamic memory
    delete [] num_array;
}

void getNumbers(int *num_array, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << "Please enter number " << i + 1 << ": ";
        cin >> num_array[i];
        if (cin.fail())
        {
            // used help from google and prof to fix entering in
            cout << "FAILED\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard remaining input
            cout << "Enter the size of array: ";
            cin >> array_size;
        }
    }
    return;
}

void reverseArray(int *num_array, int array_size)
{
    for (int i = 0, j = array_size - 1; i < array_size / 2; i++, j--)
    {
        swap(num_array[i], num_array[j]);
    }
}

/*
Output: 
Enter the size of array: -3
The size of array must be greater than 0, try again.
Enter the size of array: 5

Please enter number 1: 15
Please enter number 2: 36
Please enter number 3: 9
Please enter number 4: 90
Please enter number 5: 21

The contents of the orignal array are: [15, 36, 9, 90, 21] 
The contents of the reversed array are: [21, 90, 9, 36, 15] 
*/