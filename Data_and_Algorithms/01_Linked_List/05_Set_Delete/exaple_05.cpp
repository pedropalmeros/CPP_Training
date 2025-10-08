#include <iostream>
#include "linkedlist.hpp"


using namespace std;


int main() {
    LinkedList* list = new LinkedList(0);
    cout << "Linked list created with initial value: " << list->getHead()->value << endl;
    list->printList();

    cout << "Adding a second Node" << endl; 
    list->append(2);

    list->printList();

    cout << "Inserting a new node at index 1 with a value of 5" << endl; 
    list->insert(1,5);

    list->printList();

    
    return 0;

}   