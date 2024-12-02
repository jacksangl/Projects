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
// Assignment: expander.cpp

#include <iostream>
#include <cstdlib>
#include <iomanip>

void getNumbers(int *num_array, int array_size);
int* expandArray(int *num_array, int array_size);

using namespace std;
int main()
{
    // declare variable
    int *num_array = nullptr, *expanded_array = nullptr;
    int array_size = 0, average = 0;

    // get user input
    cout << "Enter the size of array: ";
    cin >> array_size;

    // validate user input
    while (array_size <= 1)
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
            cout << "The size of array must be greater than 1, try again.\n";
            cout << "Enter the size of array: ";
            cin >> array_size;
        }
    }
    cout << "\n";

    // dynamically allocate memory to an a array sizeof the user input
    num_array = new int[array_size];

    // get numbers for array
    getNumbers(num_array, array_size);
    // expand the array
    expanded_array = expandArray(num_array, array_size);

    // display contents to user
    cout << "\nThe contents of the original array are:\n";
    for (int i = 0; i < array_size; i++)
    {
        cout << num_array[i] << " "; 
    }
    cout << "\n\nThe contents of the expanded array are:\n";
    for (int i = 0, j = array_size * 2; i < j; i++)
    {
        cout << expanded_array[i] << " "; 
    }
    cout << "\n";

    // release memory back to computer
    delete [] num_array;
    delete [] expanded_array;
}

int* expandArray(int *num_array, int array_size)
{
    int* expanded_array = new int[array_size*2];
    for (int i = 0; i < array_size; i++)
    {
        expanded_array[i] = num_array[i];
    }
    for (int i = array_size; i < array_size*2; i++)
    {
        expanded_array[i] = 0;
    }
    return expanded_array;
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

/*
Output:
Enter the size of array: 0
The size of array must be greater than 1, try again.
Enter the size of array: 5

Please enter number 1: 10
Please enter number 2: 20
Please enter number 3: 30
Please enter number 4: 40
Please enter number 5: 50

The contents of the original array are:
10 20 30 40 50 

The contents of the expanded array are:
10 20 30 40 50 0 0 0 0 0 
*/