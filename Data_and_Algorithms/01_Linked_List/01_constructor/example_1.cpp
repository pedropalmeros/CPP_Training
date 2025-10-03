#include <iostream>
#include "linkedlist.hpp"


using namespace std;


int main() {


    LinkedList* list = new LinkedList(5);


    cout << "Linked list created with initial value: " << list->getHead()->value << endl;


    list->printList();
    return 0;

}   