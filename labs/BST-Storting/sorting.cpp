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
// Assignment: InLabProj 13

#include <iostream>
#include <string>

using namespace std;

template <typename T>
int InsertionSort(T arr[], int size) {
	int i, j;
	T temp;
	int comparisonCount = 0;
	for (i = 1; i < size; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			// The following if statement compare temp and arr[j], both are array elements
			// Should increase the comparison count.
			comparisonCount += 1;
			if (temp < arr[j]) arr[j + 1] = arr[j];
			else break;
		}
		arr[j + 1] = temp;
	}

	return comparisonCount;
}

template <typename T>
int partition(T x[], int first, int last)
{
	T pivot = x[last];    // pick the last as pivot element
	int j = first - 1;    // use x[first], x[first+1]...x[j]
						  // to store smaller than pivot values
	for (int i = first; i < last; i++) {
		// The following if state makes a comparision of x[i] and pivot. Both are array elements.
		if (x[i] < pivot) {
			j += 1;
			swap(x[j], x[i]);
		}
	}
	swap(x[last], x[j + 1]);
	return j + 1;
}

// The function you need to modify
template <typename T>
int QuickSort(T x[], int first, int last) {

	int comparisonCount = 0;

	if (first < last) {
		int pi = partition(x, first, last);
		comparisonCount += last - first; // The partition process made first-last comparisons in its for loop
		comparisonCount += QuickSort(x, first, pi - 1);
		comparisonCount += QuickSort(x, pi + 1, last);
	}

	return comparisonCount;
}

// A function used by the testing program
// Do not modify
void testCase(int testArr[], int size) {
	int* arrCopyA = new int[size];
	int* arrCopyB = new int[size];
	memcpy(arrCopyA, testArr, size * sizeof(int));
	memcpy(arrCopyB, testArr, size * sizeof(int));
	int numOfCompsInsertion = InsertionSort<int>(arrCopyA, size);
	int numOfCompsQuick = QuickSort<int>(arrCopyB, 0, size-1);

	cout << "Given array: " << endl;

	for (int i = 0; i < size; i++) {
		cout << testArr[i] << " ";
	}
	cout << endl;

	cout << "The insertion sort algorithm takes " << numOfCompsInsertion << " comparisons to sort the array." << endl;
	cout << "The quicksort algorithm takes " << numOfCompsQuick << " comparisons to sort the array." << endl;

}

// The main function.
int main() {

	// Change this to test different arrays, you may also change size
	/* original
	int testArray[20] = {
		51,   23,   91,   96,   19,   22,   63,   24,
		80,   38,   15,   60,   46,   31,   25,   34,
		
	};
	*/

	// this takes 276 comparisons for quicksort vs 23 for insertion.
	int testArray[24] = {
		50,   50,   50,   50,   50,   50,   50,   50,
		50,   50,   50,   50,   50,   50,   50,   50,
		50,   50,   50,   50,   50,   50,   50,   50,
	};

	int testArray2[100] = { 
		42,  37,  11,  90,  65,  53,  75,  15,
		99,  87,  59,  19,  22,  63,  27,  74,
		88,  35,  32,  50,  13,  93,  66,  14,
		31,  45,  78,  96,  55,  70,  57,  16,
		86,  80,  25,  36,  92,  18,  28,  68,
		98,  41,  61,  62,  81,  73,  67,  34,
		30,  26,  76,   8,  10,  85,  47,  77,
		20,  40,  46,   1,  94,  21,  12,  91,
		44,  83,  29,  56,  89,  64,   6,   7,
		97,  24,  60,  52,  71,   2,  49,  38,
		84,  39,  58,  33,  79,   3,  95,  48,
		23,  43,   4,   9,  17,  69,  82,   5,
		54,  100,  72,  51
	};
	

	// pay attention to the size of the array
	testCase(testArray, 24);
	testCase(testArray2, 100);
}

/*
Output

Given array: 
50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 
The insertion sort algorithm takes 23 comparisons to sort the array.
The quicksort algorithm takes 276 comparisons to sort the array.
Given array: 
42 37 11 90 65 53 75 15 99 87 59 19 22 63 27 74 88 35 32 50 13 93 66 14 31 45 78 96 55 70 57 16 86 80 25 36 92 18 28 68 98 41 61 62 81 73 67 34 30 26 76 8 10 85 47 77 20 40 46 1 94 21 12 91 44 83 29 56 89 64 6 7 97 24 60 52 71 2 49 38 84 39 58 33 79 3 95 48 23 43 4 9 17 69 82 5 54 100 72 51 
The insertion sort algorithm takes 2696 comparisons to sort the array.
The quicksort algorithm takes 577 comparisons to sort the array.
*/