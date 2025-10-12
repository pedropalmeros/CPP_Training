#include <iostream>

using namespace std;


class Node{
    public:
        int value; 
        Node* left; 
        Node* right; 

        Node(int value){
            this->value = value; 
            left = nullptr; 
            right = nullptr; 
        } 
};


class BinarySearchTree {
    public:
        Node* root;

		BinarySearchTree(){
            root = nullptr; 
        }

        BinarySearchTree(int val){
            Node* newNode = new Node(val);
            root = newNode;
        }
		


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root;

    cout << endl;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 0x0

    */

}

