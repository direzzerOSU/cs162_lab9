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

template<typename T>
class Container {
 public:
	 // default constructor & destructor
	 Container(T<int> container);
	 ~Container() {};

	// queue member function prototypes
	void toAdd(int& reference, int& value, int N);
	void toRemove(int& reference, int& value);
	void printContainer();
	double avgSize();
	void printRound();
 private:
	 T<int> container;						// either a queue or stack when initialized
	 T<int>* containerPtr = &container;		// pointer that points to the container (queue/stack)
	 std::vector<int> sizes;	// keeps track of the queue/stack sizes for each round
};

// specify the types that will use the templates
template class queue<int>;
template class stack<std::string>;

//########################################################

//// these are the 'nodes' for each value
//// in the list
//template<typename T>
//struct QueueNode {
//   QueueNode* next = nullptr;
//   QueueNode* prev = nullptr;
//   T val;
//};
//
//// this is the 'container' for the circular
//// linked list
//template<typename T>
//class Queue {
// public:
//    Queue() { head = nullptr; }
//    Queue(T&);
//    ~Queue();
//    bool isEmpty();
//    void addBack(T&);
//    T getFront();
//    void removeFront();
//    void printQueue();
//	int randNum();
//	void toAdd(int&, int&, T&);
//	void toRemove(int&, int&);
//	void printRound();
//	int getLength();
//	void saveLength(int&);
//	double avgLength();
// private:
//    QueueNode<T>* head = nullptr;
//	std::vector<int> lengths;	// lengths of buffer during each round
//};

#endif
