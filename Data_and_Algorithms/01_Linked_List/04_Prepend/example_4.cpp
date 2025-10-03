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



    return 0;

}   