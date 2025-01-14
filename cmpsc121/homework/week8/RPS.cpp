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
// Name: <Jack Sangl>
// Section: <003L>
// Assignment: Rock Paper Scisors Game
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;
int getUserSelection();
int computerSelection();
void determineWinner(int uChoice, int cChoice, int &uScore, int &cScore);

int main()
{
    int uScore = 0, cScore = 0, uChoice, cChoice;
    while (true)
    {
        uChoice = getUserSelection();
        cChoice = computerSelection();
        determineWinner(uChoice, cChoice, uScore, cScore);
    }

}

int getUserSelection()
{
    int selection = 0;
    cout << "Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): ";
    cin >> selection;
    while (true)
    {   
        switch(selection)
        {      
            case 1:     return selection;
            case 2:     return selection;
            case 3:     return selection;
            case -1:    return selection;
            default:    cout << "Invalid selection. Enter 1, 2, 3, or -1: ";
                        cin >> selection; 
                        break;
        }
    }
}

int computerSelection()
{
    int computer = 0;
    unsigned seed = (unsigned)time(NULL);
    srand(seed);
    // num between 1 and 3
    computer = rand() % 3 + 1;
    return computer;
}

void determineWinner(int uChoice, int cChoice, int &uScore, int &cScore)
{
    if (uChoice == -1)
    {
        cout << "GAME OVER\n";
        if (uScore > cScore)
        {
            cout << "The user wins with a score of " << uScore << " to " << cScore<< endl;
        }
        else if (uScore < cScore)
        {
                        cout << "The computer wins with a score of " << cScore << " to " << uScore<< endl;
        }
        else 
            cout << "The game is a tie with user score of " << uScore << " and computer score of " << cScore << endl;
        exit(EXIT_SUCCESS);
    }
    if (cChoice == uChoice)
    {
        switch(cChoice)
        {
            case 1: cout << "User chooses rock, computer chooses rock\n TIE. NO WINNER\n";
                    break;
            case 2: cout << "User chooses paper, computer chooses paper\n TIE. NO WINNER\n";
                    break;
            case 3: cout << "User chooses scissors, computer chooses scissors\n TIE. NO WINNER\n";
                    break;
        }
        return;
    }
    switch(uChoice)
    {

        case 1:     cout << "User chooses rock, ";
                    if (cChoice == 2)
                    {
                        cout << "computer chooses paper\n";
                        cout << "COMPUTER WINS\n";
                        cScore++;
                        break;
                    }
                    else 
                    {
                        cout << "computer chooses scissors\n";
                        cout << "USER WINS\n";
                        uScore++;
                        break;
                    }
        case 2:     cout << "User chooses paper, ";
                    if (cChoice == 3)
                    {
                        cout << "computer chooses scissors\n";
                        cout << "COMPUTER WINS\n";
                        cScore++;
                        break;
                    }
                    else 
                    {
                        cout << "computer chooses rock\n";
                        cout << "USER WINS\n";
                        uScore++;
                        break;
                    }
        case 3:     cout << "User chooses scissors, ";
                    if (cChoice == 1)
                    {
                        cout << "computer chooses rock\n";
                        cout << "COMPUTER WINS\n";
                        cScore++;
                        break;
                    }
                    else 
                    {
                        cout << "computer chooses paper\n";
                        cout << "USER WINS\n";
                        uScore++;
                        break;
                    }         
    }
    return;

}


/*
Output 1:
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): -1
GAME OVER
The game is a tie with user score of 0 and computer score of 0
*/

/*
Output 2:
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 1
User chooses rock, computer chooses scissors
USER WINS
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 1
User chooses rock, computer chooses rock
 TIE. NO WINNER
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 2
User chooses paper, computer chooses rock
USER WINS
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 2
User chooses paper, computer chooses scissors
COMPUTER WINS
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 3
User chooses scissors, computer chooses paper
USER WINS
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 3
User chooses scissors, computer chooses scissors
 TIE. NO WINNER
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): -1
GAME OVER
The user wins with a score of 3 to 1
*/

/*
Output 3:
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): 4
Invalid selection. Enter 1, 2, 3, or -1: -2
Invalid selection. Enter 1, 2, 3, or -1: 1
User chooses rock, computer chooses scissors
USER WINS
Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): -1
GAME OVER
The user wins with a score of 1 to 0
*/