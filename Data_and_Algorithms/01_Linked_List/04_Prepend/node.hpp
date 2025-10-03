#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }

        void printValue() {
            cout << "Node Value: " << value << endl;
        }

        void printNext() {
            if (next) {
                cout << "Next Node Value: " << next->value << endl;
            } else {
                cout << "Next Node is nullptr" << endl;
            }
        }
}; 

#endif // NODE_H