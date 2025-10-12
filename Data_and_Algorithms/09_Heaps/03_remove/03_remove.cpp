#include <vector>
#include <iostream> 
#include <climits>


using namespace std; 

class Heap{
    private:
        vector<int> heap;

    private:
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

        void insert(int value){
            heap.push_back(value);
            // position of the last element of the heap
            int current = heap.size()-1; 
            while(current>0 && heap[current] > heap[parent(current)]){ // if current = 0 we are at the top of the heap
                swap(current,parent(current));
                current = parent(current);   
            }
        }

        void sinkDown(int index){
            // this function compares the parent with the children
            // and swaps the place with the one with the greatest value.
            int maxIndex = index; 
            while(true){
                int leftIndex = leftChild(index); 
                int rightIndex = rightChild(index);
                if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]){
                    maxIndex = leftIndex; 
                }
                if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]){
                    maxIndex = rightIndex; 
                }
                if (maxIndex != index){
                    swap(index, maxIndex);
                    index = maxIndex;
                }else{
                    return;
                }
            }

        }

        int remove(){
            if (heap.empty()){
                return INT_MIN;
            }

            int maxValue = heap.front();

            if(heap.size() == 1){
                heap.pop_back();
            }else{
                heap[0] = heap.back(); 
                heap.pop_back(); 
                sinkDown(0);

            }

            return maxValue;
        }

};