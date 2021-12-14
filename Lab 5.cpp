/*
    Name: Isaac Andersen
    Description: Write a number-guessing game in which the computer selects a random 
    number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At 
    the end of each game, users should be told whether they won or lost, and then be asked 
    whether they want to play again. When the user quits, the program should output the 
    total number of wins and losses. To make the game more interesting, the program 
    should vary the wording of the messages that it outputs for winning, for losing, and for 
    asking for another game. Create 10 different messages for each of these cases, and use 
    random numbers to choose among them. This application should use at least one Do-
    While loop and at least one Switch statement. Write your C++ code using good style and 
    documenting comments. You should use functions in your code as well. Your source 
    code file should be called Lab5.cpp.
    Due: December 13, 2021
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void numberGenerate();
void winResp();
void loseResp();

int main()
{
	numberGenerate(); // Calls the function
}

 void numberGenerate()
{
	srand(unsigned int(time(NULL)));

	int ranNum = round(rand() % 100 + 1); // Sets the variables
	int userIn;
	int numGuess = 20;

	do // Sets what is being performed while numGuess is greater than or equal to 1
	{
		cout << "Try to guess the number between 0 and 100. You have " << numGuess << " guesses: " << endl;

		cin >> userIn;

		if (ranNum == userIn) // Checks if the user input is the random number
		{
			winResp();
			numGuess = 0;
			break;
		}
		else
		{
			loseResp();
			numGuess == numGuess--;
		}
		
	} while (numGuess >= 1);
}

void winResp() // Creates a function for the win responses
{
    int randOut = round(rand() % 10 + 1);
    switch (randOut) // Randomly selects a response out of the list of available responses
    {
    case 1:
    {
        cout << "You win" << endl;
        break;
    }
    case 2:
    {
        cout << "Nice!" << endl;
        break;
    }
    case 3:
    {
        cout << "Congragulations!" << endl;
        break;
    }
    case 4:
    {
        cout << "*Careless Whisper Ensues*" << endl;
        break;
    }
    case 5:
    {
        cout << "You got lucky" << endl;
        break;
    }
    case 6:
    {
        cout << "Good Job" << endl;
        break;
    }
    case 7:
    {
        cout << "Right on!" << endl;
        break;
    }
    case 8:
    {
        cout << "Wooo let's go!" << endl;
        break;
    }
    case 9:
    {
        cout << "Did you cheat?" << endl;
        break;
    }
    case 10:
    {
        cout << "Well that was fast" << endl;
        break;
    }
    }
}

void loseResp() // Creates a function for the lose responses
{
    int randOut2 = round(rand() % 10 + 1);
    switch(randOut2) // Randomly selects a response out of the list of available responses
    {
    case 1:
    {
        cout << "You lost" << endl;
        break;
    }
    case 2:
    {
        cout << "Sorry" << endl;
        break;
    }
    case 3:
    {
        cout << "Better luck next time" << endl;
        break;
    }
    case 4:
    {
        cout << "*Sad Trombone Music*" << endl;
        break;
    }
    case 5:
    {
        cout << "You Died" << endl;
        break;
    }
    case 6:
    {
        cout << "Oh no! You Lost" << endl;
        break;
    }
    case 7:
    {
        cout << "Try again" << endl;
        break;
    }
    case 8:
    {
        cout << "You got this, keep trying!" << endl;
        break;
    }
    case 9:
    {
        cout << "Task failed" << endl;
        break;
    }
    case 10:
    {
        cout << "Misstype maybe?" << endl;
        break;
    }
    }
}