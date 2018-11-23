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

// these are the 'nodes' for each value
// in the list
struct QueueNode {
   QueueNode* next = nullptr;
   QueueNode* prev = nullptr;
   int val;
};

// this is the 'container' for the circular
// linked list
class Queue {
 public:
    Queue() { head = nullptr; }
    Queue(int x);
    ~Queue();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
	int randNum();
 private:
    QueueNode* head = nullptr;
};

#endif
