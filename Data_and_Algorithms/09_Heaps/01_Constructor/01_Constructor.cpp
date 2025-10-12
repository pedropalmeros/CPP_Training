#include <vector>
#include <iostream> 


using namespace std; 

class Heap{
    private:
        vector<int> heap;

        int leftChild(int index){
            // root at pos = 1;
            //return 2*index;
        
            // root at pos = 0
            return 2*index + 1;
        }

        int rightChild(int index){
            // root at pos = 1
            // return 2*index + 1; 

            // root at pos = 0
            return 2*index + 2; 
        }

        int parent(int index){
            // root at pos = 1
            // return index/2; 

            // root at pos = 0
            return (index -1)/2; 
        }

        void swap(int index1, int index2){
            int temp;
            temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }

};