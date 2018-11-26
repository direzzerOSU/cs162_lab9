/*********************************************************************
** Program name: Stack and Queue STL Containers
                 [STL = Standard Template Library]
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Implements input validation functions.
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include "CircularLinkedList.hpp"
#include<sstream>
#include<queue>

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
		   //initialize required variables
		   std::vector<int>* sizes;
		   int currentRound = 0;
		   int numElements = 0;
		   int numRounds, addNum, removeNum;

		   // acquire simulation settings
		   settings(numRounds, addNum, removeNum);

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
			   cout << "Round #" << currentRound << endl;
			   cout << "randAdd = " << randAdd << endl;
			   container.toAdd(addNum, randAdd, randN);
			   cout << "randRemove = " << randRemove << endl << endl;
			   container.toRemove(removeNum, randRemove);
			   sizes->insert(sizes->begin()+currentRound, container.getSize());	// keep track of the # of elements at the end of each round
			   currentRound++;

			   // print round output
			   container.printRound();
			   cout << endl << "-----------------------------------" << endl;
			   cout << endl;
		   }
	   }

	   // palindrome stack
	   else if (selection == 2) {
		   cout << "What word would you like to create a palindrome out of?" << endl << endl;
		   std::string palindrome = getStringInput();

		   Container<std::stack<std::string>, std::string> container = Container<std::stack<std::string>, std::string>();

		   for(int n=0; n<palindrome.size(); n++) {
			   std::stringstream ss;
			   ss << palindrome[n];
			   std::string x;
			   ss >> x;
			   container.add(x);
		   }
		   container.printContainer();

		   for (int n = palindrome.size(); n >= 0; n--) {
			   std::stringstream ss;
			   ss << palindrome[n];
			   std::string x;
			   ss >> x;
			   container.add(x);
		   }
		   container.printContainer();
	   }

	   // prompt the user to return to the intro menu or not
	   mainMenuReturn(status);

   }

   return 0;
}
