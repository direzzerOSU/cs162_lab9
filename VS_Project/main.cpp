/*********************************************************************
** Program name: Lab 9 | Buffer Queue & Palindrome Stack
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Implements the full program by integrating all
   header and implementation/source files with classes, function
   prototypes, functions, and #include libraries, respectively.
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include "CircularLinkedList.hpp"
#include<sstream>
#include<queue>
#include<ctime>
#include<cstring>

// main program implementation
int main() {
   // initialize the 'seed' for generating random ints
   std::srand(time(0));

   // begin with the introduction menu -- prompt to start/quit the program
   bool status = true;
   cout << endl;

   // keep returning to the intro menu until the player decides to quit
   while (status) {
	   introMenu(status);
	   cout << endl;

	   // quit the program
	   if (!status) {
		   break;	// break out of the loop
	   }

	   // user chooses the function he/she wants to run
	   int selection = 9;
	   programSelection(selection);
	   cout << endl;

	   // queue of integers
	   if (selection == 1) {
		   //initialize required variables
		   int currentRound = 0;
		   int numElements = 0;
		   int numRounds, addNum, removeNum;

		   // acquire simulation settings
		   settings(numRounds, addNum, removeNum);
		   cout << endl << "----------------------------------------------" << endl << endl;

		   // initialize the queue / list
		   Container<std::queue<int>, int> container = Container<std::queue<int>, int>(); 

		   // loop through each round until max rounds has been reached
		   while (currentRound < numRounds) {
			   // values that determine outcomes | whether to add/remove a value
			   int randN, randAdd, randRemove;
			   randN = (randNum() % 1000) + 1;
			   randAdd = (randNum() % 100) + 1;
			   randRemove = (randNum() % 100) + 1;

			   // cout << "queue.randNum() = " << queue->randNum() << endl;

			   // add/remove values from the queue / list
			   cout << "Round #" << currentRound+1 << endl << endl;
			   cout << "Random numbers for deciding whether an int is added/removed from the queue:" << endl;
			   cout << "     Add = " << randAdd << endl;
			   container.toAdd(addNum, randAdd, randN);
			   cout << "  Remove = " << randRemove << endl << endl;
			   container.toRemove(removeNum, randRemove);
			   container.storeSize(container.getSize());	// keep track of the # of elements at the end of each round
			   currentRound++;

			   // print round output
			   container.printRound();
			   cout << endl << "----------------------------------------------" << endl;
			   cout << endl;
		   }
	   }

	   // palindrome stack
	   else if (selection == 2) {
		   cout << "What word would you like to create a palindrome out of?" << endl;
		   cout << "Palindrome: ";
		   std::string palindrome;
		   getline(cin.ignore(), palindrome, '\n');
		   //cout << "palindrome = " << palindrome << endl;

		   // copy the input into an array of characters
		   Container<std::stack<char>, char> container = Container<std::stack<char>, char>();
		   char chars[palindrome.size()];
		   strcpy(chars, palindrome.c_str());

		   // add the characters to the container
		   for (int n = 0; n < palindrome.size(); n++) {
			   //cout << "chars[n] = " << chars[n] << endl;
			   container.add(chars[n]);
		   }

		   // add the characters to the container (in reverse)
		   for (int n = palindrome.size() - 1; n >= 0; n--) {
			   //cout << "chars[n] = " << chars[n] << endl;
			   container.add(chars[n]);
		   }
		   // print the container's contents (as a palindrome)
		   cout << endl;
		   container.printContainer();
		   cout << endl;
	   }
	   // prompt the user to return to the intro menu or not
	   mainMenuReturn(status);
	   cout << endl;
   }

   return 0;
}
