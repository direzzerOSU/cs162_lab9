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

// these are the 'nodes' for each value
// in the list
template<typename T>
struct QueueNode {
   QueueNode* next = nullptr;
   QueueNode* prev = nullptr;
   T val;
};

// this is the 'container' for the circular
// linked list
template<typename T>
class Queue {
 public:
    Queue() { head = nullptr; }
    Queue(T&);
    ~Queue();
    bool isEmpty();
    void addBack(T&);
    T getFront();
    void removeFront();
    void printQueue();
	int randNum();
	void toAdd(int&, int&, T&);
	void toRemove(int&, int&);
	void printRound();
	int getLength();
	void saveLength(int&);
	double avgLength();
 private:
    QueueNode<T>* head = nullptr;
	std::vector<int> lengths;	// lengths of buffer during each round
};

#endif
