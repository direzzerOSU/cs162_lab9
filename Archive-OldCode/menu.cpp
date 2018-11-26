/*********************************************************************
** Program name: Stack and Queue STL Containers
                 [STL = Standard Template Library]
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Implements the main menu and other menu-like
   functions.
*********************************************************************/

#include "menu.hpp"

// game introduction menu
void introMenu(bool& status) {
   // introduction
   string program_name = "Linear Data Structures with STL Containers Program";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;

   cout << "What would you like to do?" << endl;
   cout << "   1. Start" << endl;
   cout << "   2. Exit" << endl;
   cout << endl << "Selection: ";
   int quit;
   cin >> quit;
   intValidation(quit);

   // begin the game
   if(quit == 1) {
      status = true;
   }
   else if(quit == 2) {
      // end the game
      cout << endl;
      status = false;
   }
}

// allow the user to select which program he/she wants to run
void programSelection(int& selection) {
	// prompt the user with menu options
	cout << "What program would you like to start?" << endl;
	cout << "	1. Queue of integers" << endl;
	cout << "	2. Palindrome stack" << endl;

	cout << endl << "Selection: ";
	cin >> selection;
	intValidation(selection);

	// ensure a valid menu option is chosen
	while (selection != 1 && selection != 2) {
		cout << "Whoops! You didn't choose a valid option... Please try again..." << endl;
		cout << "Selection: ";
		cin >> selection;
		intValidation(selection);
	}
}

// acquire required info from the menu
void settings(int& numRounds, int& addNum, int& removeNum) {
   cout << "Please enter the following simulation settings: " << endl;

   // # of simulation rounds
   cout << "   # of rounds: ";
   cin >> numRounds;
   intValidation(numRounds);

   // probability that a random number will be added at the end of the buffer
   cout << "   % chance that a random number will be added to the end of the buffer: ";
   cin >> addNum;
   intValidation(addNum);

   // probability that a random number will be removed from the end of the buffer
   cout << "   % chance that a random number will be removed from the front of the buffer: ";
   cin >> removeNum;
   intValidation(removeNum);
}

// the main/primary menu that users arrive at after starting the program;
// this menu allows the user to navigate to various areas of the program
// to perform different transactions and view different data.
void OLD_GameMenu(char& option1) {
   // introduction
   string program_name = "Doubly-linked List";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;

   while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
      // menu prompt
      cout << "Please select an option from the following choices:" << endl;
      cout << "Input the option's corresponding letter to make a selection..." << endl << endl;

      // menu choices
      cout << "    a. Add a new node to the head" << endl;
      cout << "    b. Add a new node to the tail" << endl;
      cout << "    c. Delete the first node in the list" << endl;
      cout << "    d. Delete the last node in the list" << endl;
      cout << "    e. Traverse the list reversely (tail to head)" << endl;
      cout << "    f. Print the head node's value" << endl;
      cout << "    g. Print the tail node's value" << endl;
      cout << "    h. Exit the program" << endl << endl;

      cout << "Selection: ";
      cin >> option1;
      charValidation(option1);

      if(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
         cout << endl;
         while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
            cout << "Uh oh! It looks like you didn't input a valid menu option... Please try again." << endl << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Selection: ";
            cin >> option1;
            cout << endl;
         }
      }
      else {
         cout << endl;
      }
      if(tolower(option1) == 'f') {
         break;
      }
   }
}

// a small prompt that asks the user if he/she would like to return to the main
// menu; this was intended to appear after the user performs some transaction
void mainMenuReturn(bool& x) {
   int option = 0;
   while(option != 9 && option != 5) {
      cout << "Do you want to return to the main menu?" << endl;
      cout << "   1. Yes" << endl;
      cout << "   2. No" << endl;
      cout << endl << "Selection: ";
      cin >> option;
      intValidation(option);

      if(option == 1) {
         x = true;
         option = 9;       // let the program escape the 'while loop' & return to the menu
      }

      else if(option == 2) {
         cout << endl << "Do you want to exit the program?" << endl;
         cout << "   1. Yes" << endl;
         cout << "   2. No" << endl;
         cout << endl << "Selection: ";
         cin >> option;
         intValidation(option);

         // escape the 'while loop' & quit the program
         if(option == 1) {
            x = false;
            option = 5;
         }

         // do nothing and let the program run back through the 'while loop'
         else if(tolower(option) == 2) {
            cout << endl;
            //option = 'n'
         }
      }
   }
}

int randNum() {
	return rand();
}

std::string getStringInput() {
	cout << "Please enter a string (one word): ";
	std::string input = "";
	cin >> input;
	strValidation(input);

	return input;
}