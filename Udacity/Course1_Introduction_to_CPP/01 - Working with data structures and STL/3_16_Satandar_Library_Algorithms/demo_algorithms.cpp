#include <iostream> 
#include <vector> 
#include <list> 
#include <algorithm> 
#include <numeric> 

using namespace std; 

int main(){
    // --- Input Iterator: std::copy ---
    std::vector<int> original = {1,2,3,4,5}; 
    std::vector<int> copy_target(original.size()); 

    std::vector<int> copy_target1 = {0, 0, 0, 0, 0 };

    // Implement std::copy
    std::copy(original.begin(), original.end(), copy_target.begin()); 
    std::copy(original.begin(), original.end(), copy_target1.begin());
    // std::copy(original.begin(), original.end(), copy_target1.begin()+1); 

    std::cout << "Copied vector: "; 
    for( int val : copy_target) std::cout << val << " ";
    std::cout << std::endl; 

    // --- Forward Iterator: std::accumulate ---
    // Implement std::accumulate
    int sum = std::accumulate(original.begin(), original.end(), 0 ); 
    std::cout << "Sum using accumulate: " << sum << std::endl; 

    sum = std::accumulate(original.begin(), original.end(), 10); 
    std::cout << "Sum using accumulate: " << sum << std::endl; 


    sum = std::accumulate(original.begin()+1, original.end(),0);
    std::cout << "Sum using accumulate: " << sum << std::endl; 

    // --- Bidirectional Iterator: std::list::reverse --
    std::list<int> num_list = {10, 20, 30, 40};

    // Implement reverse
    num_list.reverse(); 


    // vectors don't have reverse method, in this case it is convenient
    // to use the std::reverse    
    std::vector<int> num_vector = {10, 20, 30, 40}; 
    std::reverse(num_vector.begin(), num_vector.end()); 

    std::cout << "Reversed list: "; 
    for(int val : num_list) std::cout << val << " "; 
    std::cout << std::endl; 

    std::cout << "Reversed vector: ";
    for(int val : num_vector) std::cout << val <<" "; 
    std::cout << std::endl; 

    // --- Random Access Iterator: std::sort and index-based access ---
    std::vector<int> data = {8, 2, 7, 4, 1}; 

    // Implement sort
    std::sort(data.begin(), data.end());

    std:;cout << "Sorted vector: "; 
    for(int val : data) std::cout << val << " "; 
    std::cout << std::endl;

    return 0; 
}