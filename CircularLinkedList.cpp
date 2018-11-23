/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Implements various functions within the QueueNode
   struct and Queue class required to implement a program that
   uses circular linked lists
*********************************************************************/

#include "CircularLinkedList.hpp"

// initializes a new list with a specific value for the first node
Queue::Queue(int x) {
   head = new QueueNode();
   head->val = x;
}

// Queue class destructor
Queue::~Queue() {
   if(head == nullptr) {
   }
   
   else {
      QueueNode* node = head->next;
      QueueNode* nodeDelete = head;
      
      // iterate through the list
      while(node != nullptr && node != head) {
         delete nodeDelete;
         nodeDelete = node;
         node = node->next;
      }
      
      delete nodeDelete;
//      delete node;
   }
}

// indicates whether the list is empty or not
bool Queue::isEmpty() {
   if(head == nullptr) {
      return true;
   }
   else {
      return false;
   }
}

// adds a new node to the back of the list
void Queue::addBack(int value) {
   if(head == nullptr) {
      head = new QueueNode();
      head->val = value;
   }

   else {
      QueueNode* node = head;

      // finds the last node in the list
      while(node->next != nullptr && node->next != head) {
         node = node->next;
      }

      node->next = new QueueNode();
      node->next->val = value;
      node->next->prev = node;
      node = node->next;
      node->next = head;
      head->prev = node;
   }
}

int Queue::getFront() {
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
   }
   else {
      return head->val;
   }
}

void Queue::removeFront() {
   
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
   }

   else {
      
      if(head->next == nullptr && head->prev == nullptr) {
         delete head;
         head = nullptr;
         cout << "List is now empty..." << endl;
      }

      else {
         QueueNode* node = head->next;

         while(node->next != nullptr && node->next != head) {
            node = node->next;
         }

         QueueNode* temp = head;
         head = head->next;
         delete temp;
         
         head->prev = node;
         node->next = head;
      }
   }
}

void Queue::printQueue() {
   if(head == nullptr) {
      cout << "List is empty..." << endl;
   }

   else {
      cout << "Circular Linked List: ";
      QueueNode* node = head;
      cout << node->val << " ";
      node = node->next;
      while(node != nullptr && node != head) {
         cout << node->val << " ";
         node = node->next;
      }
   }
}

int Queue::randNum() {
	return rand();
}