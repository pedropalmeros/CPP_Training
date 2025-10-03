#include "linkedlist.hpp"

LinkedList::LinkedList(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList()
{
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
}

Node* LinkedList::getHead(){
    return head;
}

Node* LinkedList::getTail(){
    return tail;
}

int LinkedList::getLength(){
    return length;
}

void LinkedList::printHead(){
    cout <<"Head: " << head->value << endl; 
}

void LinkedList::printTail(){
    cout <<"Tail: " << tail->value << endl;
}


void LinkedList::printList(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void LinkedList::appendOwn(int value){
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

void LinkedList::append(int value){
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

void LinkedList::delete_last_own(){
    // The main objective is to loop accordingly to the linked list length trying to find the pointer
    // that points to the last elment. 
    // Once the pointer has been found, i need to assign that pointer to the tail . 
    // After that I can delete the last node, to be able to delete that last node I need also the pointer
    if (this->length != 0){
        if (this->length==1){
        this->head = nullptr;
        this->head->next = nullptr;
        this->tail = nullptr; 
        this->tail->next = nullptr;
    }
    if (this->length >=2){
        // this is valid if we have two or more nodes
        Node* tempNode = head; 
        for (int i = 1; i < this->length-1; i++){
            tempNode=tempNode->next; 
        }
        // We are in the last node
        this->tail = tempNode;
        tail->next = nullptr;
        length--;
    }
    }  
}

void LinkedList::delete_last(){
    /* CASES TO BE ADDRESSED
        1.- Empty list
             * In this case there nothing to do 
        2.- List with one element
             * In this case the head and tail might be pointing to nullptr
             * decrease length of the list
        3.- List with more than 2 elements. 
             * create pre and temp nodes
             create a loop that loops until the next pointer is nullpointer
             temp->next
    */
    // CASE WHEN THERE IS AN EMPTY LIST. 
    if (length==0) return; 
    if (length==1){
        head = nullptr; 
        tail = nullptr;
    }else{
        Node* temp = head;
        Node* pre = head;
        while(temp->next!=nullptr){
            pre = temp; 
            temp = temp->next;                
        }
        tail = pre; 
        tail->next = nullptr; 
        length--;
        delete temp;
    }
}
