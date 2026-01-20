#include <iostream> 
#include <vector> 

using namespace std; 

int main(){
    // pizza party
    std::string rsvp_response[3] = {"yes", "no", "maybe"}; 

    // automatically order 1 pizza
    // automatically link to the ordering website

    // add to cart as response roll in 
    std::vector<std::string> responded_yes = {"Myself"};

    responded_yes.push_back("Jonny"); 
    responded_yes.push_back("Jane"); 

    std::cout << "PRINTING FROM ARRAY" << endl; 
  
    // array
    for(std::string response : rsvp_response){
        std::cout << response << std::endl;
    }
    std::cout << endl << endl;
    std::cout << "PRINTING FROM VECTOR []" << endl; 
    // vector
    for (std::string name : responded_yes){
        std::cout << name << endl;
    }


}