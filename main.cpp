/*********************************************************************
** Program name: Stack and Queue STL Containers
                 [STL = Standard Template Library]
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Implements input validation functions.
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
// #include "containersSTL.hpp"
#include "CircularLinkedList.hpp"
#include<sstream>

int main() {
   // initialize the 'seed' for generating random ints
   std::srand(time(0));

   // begin with the introduction menu -- prompt to start/quit the program
   bool status = true;

   while (status) {
	   introMenu(status);

	   if (!status) {
		   break;	// break out of the loop
	   }

	   int selection = 9;
	   programSelection(selection);

	   // queue of integers
	   if (selection == 1) {
		   // acquire simulation settings
		   int currentRound = 0;
		   int numRounds, addNum, removeNum;
		   settings(numRounds, addNum, removeNum);

		   // initialize the queue / list
		   Queue<int>* queue = new Queue<int>();

		   while (currentRound < numRounds) {
			   // values that determine outcomes | whether to add/remove a value
			   int randN, randAdd, randRemove;
			   randN = (randNum() % 1000) + 1;
			   randAdd = (randNum() % 100) + 1;
			   randRemove = (randNum() % 100) + 1;

			   // cout << "queue.randNum() = " << queue->randNum() << endl;

			   // add/remove values from the queue / list
			   cout << "Round #" << currentRound << endl;
			   cout << "randAdd = " << randAdd << endl;
			   queue->toAdd(addNum, randAdd, randN);
			   cout << "randRemove = " << randRemove << endl << endl;
			   queue->toRemove(removeNum, randRemove);
			   queue->saveLength(currentRound);
			   currentRound++;

			   // print round output
			   queue->printRound();
			   cout << endl << "-----------------------------------" << endl;
			   cout << endl;
		   }
		   delete queue;	// free memory of the linked list
	   }

	   // palindrome stack
	   else if (selection == 2) {
		   cout << "What word would you like to create a palindrome out of?" << endl << endl;
		   std::string palindrome = getStringInput();

		   Queue<std::string>* queue = new Queue<std::string>();

		   for(int n=0; n<palindrome.size(); n++) {
			   std::stringstream ss;
			   ss << palindrome[n];
			   std::string x;
			   ss >> x;
			   queue->addBack(x);
		   }
		   queue->printQueue();

		   for (int n = palindrome.size(); n >= 0; n--) {
			   std::stringstream ss;
			   ss << palindrome[n];
			   std::string x;
			   ss >> x;
			   queue->addBack(x);
		   }
		   queue->printQueue();
		   delete queue;
	   }

	   // prompt the user to return to the intro menu or not
	   mainMenuReturn(status);

   }

   return 0;
}
