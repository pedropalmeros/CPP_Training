/*
Goal: Practice calling methods and accessing membersthrough pointers (->)
and linking parent pointers.

Tasks:
- Create a few `Node` objects and store pointers to them in a
    `std::vector<Node*>.
- Mark current node as visited by calling a method via ->.
- For each neighbor pointer:
    - Set its `parent` to the current pointer
    - Mark it visited via ->.
- Print each neighbor's `id`,`visited`, and  `parent`id. 

*/

// Micro-Exercise 1: Pointer-to-object member access with `->`
#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int id;
    bool visited = false;
    Node* parent = nullptr;

    void mark() { visited = true; }
};

int main() {
    Node a{0}, b{1}, c{2};

    Node* current = &a;
    std::vector<Node*> neighbors = { &b, &c };

    // TODO: Mark current as visited using a pointer call.
    current->mark();
    // TODO: For each neighbor pointer:
    //   - set neighbor->parent = current
    for(Node* neighbor : neighbors){
        neighbor->parent = current;
        neighbor->mark();
    }
    //   - mark neighbor visited via neighbor->mark()

    for(Node* neighbor : neighbors){
        std::cout << "Neighbor id= " << neighbor->id; 

        std::cout << " visted= " << neighbor->visited ? "true" : "false";
        
        std::cout << " parent=";
        if (neighbor->parent != nullptr) {
            std::cout << neighbor->parent->id;
        } else {
            std::cout << -1;
        }
        std::cout << endl; 

    }

    // TODO: Print each neighbor's id, visited, and parent id.
    return 0;
}
