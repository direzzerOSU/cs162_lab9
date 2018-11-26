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
template<typename T>
Container<T>::Container(T<int> container) {
	containerPtr = new T();
}

// evaluates whether to add the random value to the end of the queue/stack & does so
template<typename T>
void Container<T>::toAdd(int& reference, int& value, int N) {
	// add the value to the back of the queue/stack
	if (value <= reference) {
		container->push(N);
	}
	// do not add the value to the back of the queue/stack
	else {
		// do nothing
	}
}

// evaluates whether to remove the front queue/stack value & does so
template<typename T>
void Container<T>::toRemove(int& reference, int& value) {
	// remove the front value in the queue/stack
	if (value <= reference && head != nullptr) {
		container->pop();
	}
	// do not remove the queue/stack's front value
	else {
		// do nothing
	}
}

// prints data for each round in the queue/stack of integer values
template<typename T>
void Container<T>::printRound() {
	printContainer();
	cout << "Container Length: " << sizes->back() << endl;
	cout << "Average Container Length: " << avgLength() << endl;
}

// prints the queue/stack of integers
template<typename T>
void Container<T>::printContainer() {
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
template<typename T>
double Container<T>::avgSize() {
	double avg = 0.00;	// variable that contains the average queue size over n rounds

	// iterate over each element in the vector (of the # of ints in the queue at the end of each round)
	for (int n = 0; n < sizes.size(); n++) {
		avg += static_cast<double>(sizes[n]);
	}

	return avg / static_cast<double>(sizes.size());
}

//// specify the types that will use the templates
//template class queue<int>;
//template class stack<std::string>;

//##################################################################

//// initializes a new list with a specific value for the first node
//template<typename T>
//Queue<T>::Queue(T& x) {
//   head = new QueueNode<T>();
//   head->val = x;
//}
//
//// Queue class destructor
//template<typename T>
//Queue<T>::~Queue() {
//   if(head == nullptr) {
//   }
//   
//   else {
//      QueueNode<T>* node = head->next;
//      QueueNode<T>* nodeDelete = head;
//      
//      // iterate through the list
//      while(node != nullptr && node != head) {
//         delete nodeDelete;
//         nodeDelete = node;
//         node = node->next;
//      }
//      
//      delete nodeDelete;
////      delete node;
//   }
//}
//
//// indicates whether the list is empty or not
//template<typename T>
//bool Queue<T>::isEmpty() {
//   if(head == nullptr) {
//      return true;
//   }
//   else {
//      return false;
//   }
//}
//
//// adds a new node to the back of the list
//template<typename T>
//void Queue<T>::addBack(T& value) {
//   if(head == nullptr) {
//      head = new QueueNode<T>();
//      head->val = value;
//   }
//
//   else {
//      QueueNode<T>* node = head;
//
//      // finds the last node in the list
//      while(node->next != nullptr && node->next != head) {
//         node = node->next;
//      }
//
//      node->next = new QueueNode<T>();
//      node->next->val = value;
//      node->next->prev = node;
//      node = node->next;
//      node->next = head;
//      head->prev = node;
//   }
//}
//
//template<typename T>
//T Queue<T>::getFront() {
//   if(isEmpty() == true) {
//      cout << "List is empty..." << endl;
//   }
//   else {
//      return head->val;
//   }
//}
//
//template<typename T>
//void Queue<T>::removeFront() {
//   
//   if(isEmpty() == true) {
//      cout << "List is empty..." << endl;
//   }
//
//   else {
//      
//      if(head->next == nullptr && head->prev == nullptr) {
//         delete head;
//         head = nullptr;
//         cout << "List is now empty..." << endl;
//      }
//
//      else {
//         QueueNode<T>* node = head->next;
//
//         while(node->next != nullptr && node->next != head) {
//            node = node->next;
//         }
//
//         QueueNode<T>* temp = head;
//         head = head->next;
//         delete temp;
//         
//         head->prev = node;
//         node->next = head;
//      }
//   }
//}
//
//template<typename T>
//void Queue<T>::printQueue() {
//   if(head == nullptr) {
//      cout << "List is empty..." << endl;
//   }
//
//   else {
//      cout << "Circular Linked List: ";
//      QueueNode<T>* node = head;
//      cout << node->val << " ";
//      node = node->next;
//      while(node != nullptr && node != head) {
//         cout << node->val << " ";
//         node = node->next;
//      }
//	  cout << endl;
//   }
//}
//
//template<typename T>
//int Queue<T>::randNum() {
//	return rand();
//}
//
//// evaluates whether to add the random value to the end of the queue & does so
//template<typename T>
//void Queue<T>::toAdd(int& reference, int& value, T& N) {
//	// add the value to the back of the queue
//	if (value <= reference) {
//		addBack(N);
//	}
//	// do not add the value to the back of the queue
//	else {
//		// do nothing
//	}
//}
//
//// evaluates whether to remove the front queue value & does so
//template<typename T>
//void Queue<T>::toRemove(int& reference, int& value) {
//	// remove the front value in the queue
//	if (value <= reference && head != nullptr) {
//		removeFront();
//	}
//	// do not remove the queue's front value
//	else {
//		// do nothing
//	}
//}
//
//// get the number of values in the queue/list
//template<typename T>
//int Queue<T>::getLength() {
//	int length = 0;
//	if (head == nullptr) {
//		//length++;
//	}
//	else {	
//		QueueNode<T>* node = head;
//		length++;
//		while (node->next != head && node->next != nullptr) {
//			node = node->next;
//			length++;
//		}
//	}
//	return length;
//}
//
//// prints data for each round in the queue of integer values
//template<typename T>
//void Queue<T>::printRound() {
//	//cout << "Queue: ";
//	printQueue();
//	cout << "Queue Length: " << getLength() << endl;
//	cout << "Average Queue Length: " << avgLength() << endl;
//}
//
//// stores the length of the queue in the class' vector
//template<typename T>
//void Queue<T>::saveLength(int& round) {
//	std::vector<int>::iterator it = lengths.begin() + round;
//	lengths.insert(it, getLength());
//}
//
//// calculates the average length of the queue of integers
//template<typename T>
//double Queue<T>::avgLength() {
//	double x = 0; 
//	for (int n = 0; n < lengths.size(); n++) {
//		x += lengths[n];
//	}
//	return x / lengths.size();
//}
//
//template class Queue<int>;
//template class Queue<std::string>;