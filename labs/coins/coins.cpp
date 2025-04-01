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
// Assignment: inLab proj 10
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int maxCoins(int * board, int start){
	if (start < 0) 
		return 0;
	
	return board[start] + max(maxCoins(board, start-3), maxCoins(board, start-2));
	
}

/******************************************************************************
 * Test driver main function.
 * DO NOT modify the main function.
 ******************************************************************************/

void TestCase(int * board, int start, int size){
	cout << "Test Case: Board Configuration: ";
	for(int i=0; i<size; i++){
		cout << board[i] << " ";
	}
	cout << endl;
	cout << "Starting index is " << start << endl;
	int testresult = maxCoins(board, start);
	cout << "For this test case, the max number of coins we can collect is "
	  << testresult << endl;
}

int main() {

    int board1[] = {1,1,15,6,1,0,0};
    TestCase(board1, 6, 7); // Max 17 coins collected

    int board2[] = {20,6,1,1,8,4,0,0};
    TestCase(board2, 7, 8); // Max 29 coins collected

    int board3[] = {0,0,0};
    TestCase(board3, 2, 3); // 0 coins collected
}

/*
Test Case: Board Configuration: 1 1 15 6 1 0 0 
Starting index is 6
For this test case, the max number of coins we can collect is 17
Test Case: Board Configuration: 20 6 1 1 8 4 0 0 
Starting index is 7
For this test case, the max number of coins we can collect is 29
Test Case: Board Configuration: 0 0 0 
Starting index is 2
For this test case, the max number of coins we can collect is 0
*/