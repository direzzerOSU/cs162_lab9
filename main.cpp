/*********************************************************************
** Program name: Stack and Queue STL Containers
                 [STL = Standard Template Library]
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Implements input validation functions.
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include "containersSTL.hpp"

int main() {
   // initialize the 'seed' for generating random ints
   std::srand(time(0));

   // begin with the introduction menu -- prompt to start/quit the program
   bool status = true;
   introMenu(status);

   while (status) {
	   // acquire simulation settings
	   int numRounds, addNum, removeNum;
	   settings(numRounds, addNum, removeNum);

	   Queue* queue = new Queue();
	   cout << "queue.randNum() = " << queue->randNum() << endl;

	   // prompt the user to return to the intro menu or not
	   mainMenuReturn(status);

	   delete queue;
   }

   return 0;
}
