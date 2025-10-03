#include <iostream>
#include "linkedlist.hpp"


using namespace std;


int main() {
    LinkedList* list = new LinkedList(5);
    cout << "Linked list created with initial value: " << list->getHead()->value << endl;
    list->printList();

    cout << "Adding a second Node" << endl; 
    list->append(7);

    list->printList();

    list->append(10);

    cout << "Adding a new Node. " << endl;
    list->printList();


    return 0;

}   