#include <iostream>
#include "linkedlist.hpp"


using namespace std;


int main() {
    LinkedList* list = new LinkedList(11);
    cout << "Linked list created with initial value: " << list->getHead()->value << endl;
    list->printList();

    cout << "Adding a second Node" << endl; 
    list->append(3);

    list->printList();

    list->append(23);
    list->append(7);
    list->append(4);
    cout << "Initial list " << endl;
    list->printList();

    cout << "Deleting a the last Node" << endl; 
    list->delete_last();
    list->printList();


    cout << "Adding a new node at the beginning" << endl; 
    list->prepend(90);
    list->printList();

    cout << "Getting the node at index 2" << endl; 
    Node* nodeIndex2 = list->get(2);
    cout << "The value of the Node at index 2 is " << nodeIndex2->value << endl; 

    cout << "Getting the node at index -1" << endl; 
    nodeIndex2 = list->get(-1);
    cout << "The value of the Node at index 2 is " << nodeIndex2->value << endl; 


    cout << "Getting the node at index 10" << endl; 
    nodeIndex2 = list->get(10);
    cout << "The value of the Node at index 2 is " << nodeIndex2->value << endl;     



    return 0;

}   