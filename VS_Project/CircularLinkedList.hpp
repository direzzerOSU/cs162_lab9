/*********************************************************************
** Program name: Lab 9 | Buffer Queue & Palindrome Stack
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Defines the "Container" class template to implement the 
   Standard Template Library (STL)'s queue and stack containers.
*********************************************************************/

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<cstdlib>
#include<ctime>
#include<vector>
#include<queue>
using std::queue;
#include<stack>
using std::stack;

// class template (for queue & stack)
template<typename T, typename S>
class Container {
 public:
	 // default constructor & destructor
	 Container();
	 ~Container() {};

	// queue member function prototypes
	void toAdd(int&, int&, S);
	void add(S);
	void toRemove(int&, int&);
	void printContainer();
	double avgSize();
	void printRound();
	int getSize();
	void storeSize(int);
	S getElement();
	void deleteElement();
 private:
	 T container;						// either a queue or stack when initialized
	 std::vector<int> sizes;	// keeps track of the queue/stack sizes for each round
};
#endif