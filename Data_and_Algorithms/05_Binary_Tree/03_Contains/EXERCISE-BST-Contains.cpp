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
    private:
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
 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int val){
            if(root==nullptr){return false;}

            Node* temp = root;

            while(temp!=nullptr){
                // the number has been found, it shall return a true
                if (val == temp->value) {return true;}

                // the number hasn't been found
                // we have to check if we need to go to the
                // right or left. 
                if (val < temp->value){
                    // move to the left
                    temp = temp->left;

                }else if(val > temp->value){
                    // move to the right
                    temp = temp->right;
                }
            }
            // if the program is outside the while means that
            // the temp has passed the leaf and did not find the
            // number, hence, return false
            return false;
        }
        
};



int main() {
        
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);


    cout << "Contains 27: " << myBST->contains(27);
    cout << "\n\nContains 17: " << myBST->contains(17);


    /*
        EXPECTED OUTPUT:
        ----------------
        Contains 27: 1

        Contains 17: 0

    */    

}
