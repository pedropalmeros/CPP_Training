#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "node.hpp"
class LinkedList{
    private: 
        Node* head; 
        Node* tail; 
        int length;
    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        
        Node* getHead(){       
            return head;
        }
        Node* getTail(){
            return tail;
        }
        int getLength(){
            return length;
        }

        void printList(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
};

#endif // LINKEDLIST_H