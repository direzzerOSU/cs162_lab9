/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Defines classes and structs to implement the Circular
   Linked List program.
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
	void toAdd(int&, int&, int);
	void add(S);
	void toRemove(int&, int&);
	void printContainer();
	double avgSize();
	void printRound();
	int getSize();
 private:
	 T container;						// either a queue or stack when initialized
	 //T<int>* containerPtr = &container;		// pointer that points to the container (queue/stack)
	 std::vector<int> sizes;	// keeps track of the queue/stack sizes for each round
};

// specify the types that will use the templates
template class queue<int>;
template class stack<std::string>;

#endif