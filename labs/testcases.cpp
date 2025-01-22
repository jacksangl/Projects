#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void sort(int *ptr, int size);
double average(int *ptr, int size);
void drop_lowest(int *ptr, int *ptr2, int size);

int main() {
    int size;
    double avg;
    cout << "Enter in array size: ";
    cin >> size;
    int *ptr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter test score " << i+1 << ": ";
        cin >> ptr[i];
        while (ptr[i] < 0)
        {
            cout <<"Invalid Input" << endl  << "Enter test score " << i+1 << ": ";
            cin >> ptr[i];
        } 
    }
    sort(ptr, size);
    cout << endl << "The test scores in ascending order: " << endl << "==================================" << endl;
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << endl;
    } 
    avg = average(ptr, size);
    cout << "The average is: " << setprecision(2)<<fixed <<avg << endl << endl;
    
    int *ptr2 = new int [size-1];
    drop_lowest(ptr, ptr2, size);
    cout << "The test scores (dropping lowest):" << endl << "==================================" << endl;
    for (int i = 0; i < size-1; i++) {
        cout << ptr2[i] << endl;
    } 
    avg = average(ptr2, size-1);
    cout << "The average is: " << setprecision(2)<<fixed<<avg << endl;


    delete[] ptr;
    delete [] ptr2;
}

void sort(int *ptr, int size) {

    for (int i=1; i<size; i++) {
        for (int j=size-1; j>0; j--) {
            if (ptr[j] < ptr[j-1])
                swap(ptr[j], ptr[j-1]);
        }
    }
}
double average(int *ptr, int size) {
    double average = 0;
    for (int i = 0; i < size; i++){
        average += ptr[i];
    }
    average = average/size;
    return average;
}

void drop_lowest(int *ptr,int *ptr2, int size) {
    int temp=ptr[size-1];
    for (int i = 0; i < size-1; i++) {
        ptr2[i] = ptr[i+1];
    }
}

/*
Enter in array size: 6
Enter test score 1: 75
Enter test score 2: 69
Enter test score 3: 88
Enter test score 4: 91
Enter test score 5: 96
Enter test score 6: 93

The test scores in ascending order: 
==================================
69
75
88
91
93
96
The average is: 85.33

The test scores (dropping lowest):
==================================
75
88
91
93
96
The average is: 88.60
*/