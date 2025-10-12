#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


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
 

        bool insert(int value){
            Node* newNode = new Node(value);
            if (root==nullptr){
                root = newNode; 
                return true;
            }
            Node* temp = root; 
            while(true){
                if(newNode->value == temp->value) return false; 
                if(newNode->value < temp->value){
                    // move to the left

                    // the left node is empty 
                    if (temp->left == nullptr){
                        temp->left = newNode;
                        return true; 
                    }

                    // move the next left node to iterate
                    temp = temp->left;
                }else{
                    // move to the right
                    if(temp->right == nullptr){
                        temp->right = newNode; 
                        return true;
                    }

                    temp = temp->right;
                }
            }

        }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);

    /*
        THE LINES ABOVE CREATE THIS TREE:
                     2
                    / \
                   1   3
    */
        
                  

    // ROOT MUST BE PUBLIC FOR THESE LINES TO WORK
    cout << "Root: " << myBST->root->value;
    cout << "\n\nRoot->Left->Right: " << myBST->root->left->right->value;


    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 2

        Root->Left: 1

        Root->Right: 3

    */

}
