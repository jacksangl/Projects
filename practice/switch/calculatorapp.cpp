#include <iostream>
using namespace std;

int main()
{
    float num1, num2;
    char operation;
    cout << "Enter in 2 numbers to calculate (a, b)" << endl; 
    cin >> num1;
    cin >> num2;
    cout << "Enter in your operation 'a' for addition, 's' for subtraction, 'm' for multiplication, 'd' for divide': ";
    cin >> operation;
    while (operation == 'd' && num2 == 0)
    {
        cout << "Cannot divide by zero. Enter in another second number: ";
        cin >> num2;
    }
    switch(operation)
    {
        case 'a':   cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                    break;
        
        case 's':   cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                    break;

        case 'm':   cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                    break;
        case 'd':   cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                    break;
    }

}