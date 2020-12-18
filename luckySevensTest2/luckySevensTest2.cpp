// This program generates 3 numbers from 1 to 7 and counts the number of times 3 sevens come up
// Written by: Ayden Holgate
// Date: Dec. 16, 2020

// luckySevensTest2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"																								// [
#include <iostream>																								// |
#include <cstdlib>																								// | -- Libraries
#include <ctime>																								// |
using namespace std;																							// ]

int _tmain(int argc, _TCHAR* argv[])
{																												// Start of program
	srand(time(0));																								// System Clock (Seeding)
	
	int win = 0, loss = 0, winnings = 0, tokens = 100;															// [
	int spin1, spin2, spin3;																					// | -- Declare Variables
	char play = 0;																								// ]

	cout << "Do you want to play? ";																			// Asks the user if they want to play
	cin >> play;																								// User inputs whether or not they want to play

	while (play != 'N'){																						// Starts the loop
		tokens--;																								// Takes away 1 token each time they play

		spin1 = rand() % 7 + 1;																					// [
		spin2 = rand() % 7 + 1;																					// | -- Generates three random numbers from 1 to 7
		spin3 = rand() % 7 + 1;																					// ]

		if (spin1 == 7 && spin2 == 7 && spin3 == 7){															// [
			tokens += 5;																						// |
			winnings += 5;																						// | -- Checks to see if the user wins and gives them 5 tokens if they win
			win++;																								// |
		}																										// ]
		else{																									// [
			winnings --;																						// |
			loss++;																								// | -- If the user losses take away 1 from their winnings and adds 1 to the loss counter
		}																										// ]

		cout << "(" << spin1 << ")" << "(" << spin2 << ")" << "(" << spin3 << ")" << endl;						// Outputs the 3 random numbers

		cout << "Do you want to play? ";																		// Asks the user if they want to play
		cin >> play;																							// User inputs whether or not they want to play
	}																											// Ends the loop

	cout << "\nYou have won " << win << " games" << endl;														// Tells the user how many games they've won
	cout << "You have lost " << loss << " games" << endl;														// Tells the user how many games they've lost

	if (winnings < 0){																							// Checks to see if the user has gained tokens or lost tokens
		cout << "\nYou have lost " << winnings - (winnings * 2) << " tokens" << endl;							// If they've lost tokens display how many tokens they've lost
	}
	else{
		cout << "\nYou have won " << winnings << " tokens\n" << endl;											// If they've gained tokens display how many tokens they've won
	}

	return 0;
}																												// End of program