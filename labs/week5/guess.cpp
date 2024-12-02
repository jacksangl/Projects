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
// Assignment: Guessing Game


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

int main()
{
    //variables for game and bool value for looping game
    int guess, limit, correct;
    bool wrong = true;


   //prompt user to enter in upper limit of number
   std::cout<< "Enter the upper limit of the guessing number: ";
   std::cin>> limit; 
   while (limit <= 0 || limit > 100)
   {
        std::cout<< "You have entered in an invalid number!\n";
        std::cout<< "Enter the upper limit of the guessing number: ";
        std::cin>> limit; 
   }
    //create correct number to guess for game
        //equation prof gave us
        unsigned seed = (unsigned)time(NULL); 
        srand(seed);
    correct = rand() % limit + 1;


   //if valid input start the guessing game
    while (wrong)
    {
        std::cout<<"Enter your guess in between 1 and " << limit << "\n";
        std::cin>> guess;
        if (guess <= 0 || guess > limit)
        {
            std::cout<< "You have entered in an invalid number!\n";
        }
        else if (guess > correct)
        {
            std::cout<< "Too high, try again.\n";
        }
        else if (guess < correct)
        {
            std::cout<< "Too low, try again.\n";
        }
        else 
        {
            // set bool expression to false to break out of loop
            std::cout<< "Congrats, you have guessed the correct number, " << correct << "\n";
            wrong = false;
        }
    }
   
}

/*
Output 1
Enter the upper limit of the guessing number: 101
You have entered in an invalid number!
Enter the upper limit of the guessing number: 0  
You have entered in an invalid number!
Enter the upper limit of the guessing number: 50
Enter your guess in between 1 and 50
30
Too high, try again.
Enter your guess in between 1 and 50
40
Too high, try again.
Enter your guess in between 1 and 50
1 
Too low, try again.
Enter your guess in between 1 and 50
8
Congrats, you have guessed the correct number, 8
*/
