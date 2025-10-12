#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printVector(vector<int> &vect2print);
vector<int> findDuplicates(vector<int> &nums);

int main(){
    vector<int> nums{1,2,3,4,5,6,7,8,5};

    printVector(nums);




    vector<int> duplicates = findDuplicates(nums); 

    cout << "The duplicates are: " << endl; 
    printVector(duplicates);


    return 0;
}

void printVector(vector<int> &vect2print){
    for(int element : vect2print){
        cout << element << endl; 
    }
}

vector<int> findDuplicates(vector<int> &nums){
    // loop trough all elements in the nums 
    // check if the numbers are in myMap 
    // if they are not add them and set the cont to 1
    // if they are in myMap 
    //         add them to the vector
    //          increment the count appearance in myMap
    // once finished, return duplicated vector

    unordered_map<int,int> myMap; 
    myMap.clear();
    vector<int> duplicates{};


    for(int element : nums ){
        
        auto it = myMap.find(element);

        if(it == myMap.end()){
            // element is notfound/
            // we can add the element to myMap;

            myMap[element] = 1; 
            
        }else{        
            //element found
            // the element is repeated
            duplicates.push_back(element);
            it->second = it->second+1; 
    
        }
    }

    return duplicates;
 
}
