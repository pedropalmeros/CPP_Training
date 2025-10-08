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
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Find the middle node of the linked list            |
        //   | - Return type: Node*                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - 'slow' moves one step, 'fast' moves two            |
        //   | - When 'fast' reaches the end, 'slow' is at middle   |
        //   | - Return 'slow' as the middle node                   |
        //   +======================================================+

        Node* findMiddleNode(){
            Node* fast = head;
            Node* slow = head;
            // case: empty list
            if (head == nullptr) return nullptr; 
            while(fast!= nullptr){
                // case: list with only one element
                if (fast->next == nullptr) return slow; 

                fast = fast->next->next;
                slow = slow->next;
            }

            return slow;
        }

};

int main(void){

    LinkedList* list_01 = new LinkedList(1);
    
    list_01->printList();

    Node* middleNode = list_01->findMiddleNode();
    cout << "middleNode value " << list_01->findMiddleNode()->value << endl;


    list_01->append(2);
    list_01->printList();
    middleNode = list_01->findMiddleNode();
    cout << "middleNode value " << list_01->findMiddleNode()->value << endl;



    list_01->append(3);
    list_01->append(4);
    list_01->append(5);
    list_01->append(6);
    list_01->append(7);

    list_01->printList();

    middleNode = list_01->findMiddleNode();
    cout << "middleNode value " << list_01->findMiddleNode()->value << endl;

    list_01->append(8);
    cout << "middleNode value " << list_01->findMiddleNode()->value << endl;



    return 0;
}


