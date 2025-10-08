#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.hpp"
class LinkedList{
    private: 
        Node* head; 
        Node* tail; 
        int length= 0;
    public:
        LinkedList(int value);

        ~LinkedList();
        
        Node* getHead();

        Node* getTail();

        int getLength();

        void printHead();

        void printTail();

        void printLength();

        void printList();

        void append_own(int value);

        void append(int value);

        void delete_last_own();

        void delete_last();

        void prepend(int value);

        void delete_first_own();

        Node* get(int index);
};

#endif // LINKEDLIST_H