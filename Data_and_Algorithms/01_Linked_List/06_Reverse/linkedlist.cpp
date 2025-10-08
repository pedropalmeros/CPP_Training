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

void LinkedList::printLength(){
    cout << "Length: " << length << endl;
}


void LinkedList::printList(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void LinkedList::append_own(int value){
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
void LinkedList::delete_first(){
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
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

void LinkedList::prepend(int value){
    Node* newNode = new Node(value);

    if (length==0){
        head = newNode; 
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode; 
    }

    length++;  
}

void LinkedList::delete_first_own(){
    if (length==0){ 
        return;
    }else if(length==1){
        head = nullptr; 
        tail = nullptr; 
    }else{
        Node* node2Delete = head; 

        head = head->next; 

        delete node2Delete; 
    }
    length--;
}

Node* LinkedList::get(int index){
    // the index has to be GE 0 and index has to be LE the length
    
    if (index < 0 || index>length){
        return nullptr;
    }
    Node* temp = head; 
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    return temp;
}

bool LinkedList::set(int index, int value){
    if (index < 0 || index > length){
        return false;
    }
    Node* temp = head; 
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    temp->value = value; 
    return true;
}

bool LinkedList::insert(int index, int value){
    if (index < 0 || index > length){
        return false;
    }
    
    if (index == 0){
        prepend(value);
        return true;
    }

    if (index == length){
        append(value); 
        return true;
    }
    Node* newNode = new Node(value);
    Node* temp = get(index-1);
    newNode->next = temp->next;
    temp->next = newNode;

    length++;

    return true; 

}

void LinkedList::deleteNode(int index){
    if (index < 0 || index >= length) return;
    if (index == 0) return delete_first();
    if (index == length-1) return delete_last();

    Node* prev = get(index-1); 
    Node* temp = prev->next; 

    prev->next = temp->next; 

    delete temp; 
    length--;

}

void LinkedList::reverse(){
    Node* temp = head; 
    head = tail; 
    tail = temp; 
    Node* after = temp->next; 
    Node* before = nullptr; 
    for(int i = 0; i < length; i++){
        after = temp->next;
        temp->next = before; 
        before = temp;
        temp = after;
    }
}


