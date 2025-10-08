#include <iostream>
#include "linkedlist.hpp"


using namespace std;


int main() {
    LinkedList* list = new LinkedList(0);
    cout << "Linked list created with initial value: " << list->getHead()->value << endl;
    list->printList();

    cout << "Adding nodes: 2 6 9 10 15 3" << endl; 
    list->append(2);
    list->append(6);
    list->append(9);
    list->append(10);
    list->append(15);
    list->append(3);

    list->printList();

    cout << "Reversing the list: " << endl; 

    list->reverse();


    list->printList();

    
    return 0;

}   