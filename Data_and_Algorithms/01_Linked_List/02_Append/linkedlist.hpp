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

        void printHead(){
            cout << "Head: " << head->value << endl;
        }

        void printTail(){
            cout << "Tail: " << tail->value << endl;
        }

        void printLength(){
            cout << "Length: " << length << endl;
        }

        void printList(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void appendOwn(int value){
            // Note this function works but is not correct since I have to loop through all the list
            // And I didn't use the advange of the tail.
            // create the new node
            Node* newNode = new Node(value);

            // check if the list is empty
            if (length == 1){
                // emtpy list
                tail = newNode;
                head->next = newNode;
                length = 2;

            } else{ // not empty list
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = head->next;
                }

                // we are in the tail of the list
                temp->next = newNode;
                tail = newNode; 
                length+=1; 

            }
        }

        void append(int value){
            Node *newNode = new Node(value);
            if(length == 0){
                // this is deensive code, because we cannot create an emtpy linkedlist
                head = newNode; 
                tail = newNode;
            }
            else{
                tail->next = newNode; 
                tail = newNode; 
            }
            length++; 
        }
};

#endif // LINKEDLIST_H