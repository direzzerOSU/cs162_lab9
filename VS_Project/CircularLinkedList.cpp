/*********************************************************************
** Program name: Lab 9 | Buffer Queue & Palindrome Stack
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Implements various functions within the Container
   class template, which is used to implement a queue and stack from
   the Standard Template Library (STL).
*********************************************************************/

#include "CircularLinkedList.hpp"

// default constructor
template<typename T, typename S>
Container<T,S>::Container() {
	//containerPtr = new T();
}

// evaluates whether to add the random value to the end of the queue/stack & does so
template<typename T, typename S>
void Container<T,S>::toAdd(int& reference, int& value, S N) {
	// add the value to the back of the queue/stack
	if (value <= reference) {
		container.push(N);
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
		container.pop();
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
	cout << "Container Length:           " << container.size() << endl;
	cout << "Average Container Length:   " << avgSize() << endl;
	//for (int n = 0; n < sizes.size(); n++) {
	//	cout << "sizes[" << n << "] = " << sizes[n] << endl;
	//}
}

// prints the queue of integers
template<>
void Container<std::queue<int>, int>::printContainer() {
	std::queue<int> container2 = container;
	// if the queue is empty
	if (container2.empty()) {
		cout << "Container: [Empty]" << endl;
	}

	// if the queue is NOT empty
	else {
		cout << "Container:                  ";
		while (!container2.empty()) {
			cout << container2.front() << " ";
			container2.pop();
		}
		cout << endl;
	}
}

// prints the stack of strings (chars)
template<>
void Container<std::stack<char>, char>::printContainer() {
	std::stack<char> container2 = container;
	// if the queue is empty
	if (container2.empty()) {
		cout << "Container: [Empty]" << endl;
	}

	// if the queue is NOT empty
	else {
		cout << "Container: " << endl;
		while(!container2.empty()) {
			//cout << "container2.top() = " << container2.top() << endl;
			cout << container2.top() << " ";
			container2.pop();
		}
		cout << endl;
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

// stores the size (i.e., # of elements) of the queue/stack
template<typename T, typename S>
void Container<T, S>::storeSize(int x) {
	sizes.push_back(x);
}

// returns the first element in the (stack) container
template<>
char Container<std::stack<char>, char>::getElement() {
	return container.top();
}

// returns the first element in the (queue) container
template<>
int Container<std::queue<int>, int>::getElement() {
	return container.front();
}

// remove the first element in the container
template<typename T, typename S>
void Container<T, S>::deleteElement() {
	container.pop();
}

// specify the types that will use the templates
template class Container<std::queue<int>, int>;
template class Container<std::stack<char>, char>;