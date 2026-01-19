#include <iostream>
#include <queue> 
#include <vector> 
#include <string> 

// City structure to hold name and distance (used as priority)
struct City{
    std::string name;
    int distance;
};

// Sample cities
std::vector<City> cities={
    {"New York", 20},
    {"Boston",5}, 
    {"Chicago",15}, 
    {"Denver",30}
};

// Custom comparator for min-heap by city distance
class CompareByDistance{
    public:
        bool operator()(int a, int b) const{
            return cities[a].distance > cities[b].distance;
        }
};

int main(){
    // Priority queue of city indices, ordered by lowest distance
    // Priority queue -> is a < b this is what priority queue wants to know if a < b
    // if Denver < New York | 30 < 20 | this is false, hence it keeps Denver to the top
    //                                  but I want the opposite
    //  I want Denver < New York -> False | To keep New York to the top
    // That is why I have to overload the operator


    /*
    Template<
    class T, 
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
    > class priority_queue; 
    */

    std::priority_queue<int, std::vector<int>, CompareByDistance> cityQueue;

    // Push city indices into the priority queue
    cityQueue.push(0);  // New York
    cityQueue.push(1);  // Boston
    cityQueue.push(2);  // Chicago
    cityQueue.push(3);  // Denver

    std::cout << "--- City Priority Queue (Min Distance First) ---\n";

    while(!cityQueue.empty()){
        int id = cityQueue.top(); 
        std::cout << cities[id].name << " (distance = " << cities[id].distance << ")\n";
        cityQueue.pop();
    }

}

