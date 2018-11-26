/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Implements various functions within the QueueNode
   struct and Queue class required to implement a program that
   uses circular linked lists
*********************************************************************/

#include "CircularLinkedList.hpp"

// default constructor
template<typename T, typename S>
Container<T,S>::Container() {
	//containerPtr = new T();
}

// evaluates whether to add the random value to the end of the queue/stack & does so
template<typename T, typename S>
void Container<T,S>::toAdd(int& reference, int& value, int N) {
	// add the value to the back of the queue/stack
	if (value <= reference) {
		container->push(N);
	}
	// do not add the value to the back of the queue/stack
}

// inserts a value into the queue/stack
template<typename T, typename S>
void Container<T,S>::add(S x) {
	container.push(x);
}

// evaluates whether to remove the front queue/stack value & does so
template<typename T, typename S>
void Container<T,S>::toRemove(int& reference, int& value) {
	// remove the front value in the queue/stack
	if (value <= reference && !container.empty()) {
		container->pop();
	}
	// do not remove the queue/stack's front value
	else {
		// do nothing
	}
}

// prints data for each round in the queue/stack of integer values
template<typename T, typename S>
void Container<T,S>::printRound() {
	printContainer();
	cout << "Container Length: " << sizes.back() << endl;
	cout << "Average Container Length: " << avgSize() << endl;
}

// prints the queue/stack of integers
template<typename T, typename S>
void Container<T,S>::printContainer() {
	// if the queue is empty
	if (container.empty()) {
		cout << "Queue: [Empty]" << endl;
	}

	// if the queue is NOT empty
	else {
		cout << "Queue: ";
		for (int n = 0; n < container.size(); n++) {
			cout << container.front() << " ";
			container.pop();
		}
	}
}

// returns the average size of the queue over all rounds
template<typename T, typename S>
double Container<T,S>::avgSize() {
	double avg = 0.00;	// variable that contains the average queue size over n rounds

	// iterate over each element in the vector (of the # of ints in the queue at the end of each round)
	for (int n = 0; n < sizes.size(); n++) {
		avg += static_cast<double>(sizes[n]);
	}

	return avg / static_cast<double>(sizes.size());
}

// returns the length (# of elements) of the queue/stack
template<typename T, typename S>
int Container<T,S>::getSize() {
	return container.size();
}

//// specify the types that will use the templates
//template class std::queue<int>;
//template class std::stack<std::string>;