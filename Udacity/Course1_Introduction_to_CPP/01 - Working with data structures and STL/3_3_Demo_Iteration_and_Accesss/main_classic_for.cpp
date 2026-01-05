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

    cout << "PRINTING FROM ARRAY" << endl; 
    int sizeOfArray = sizeof(rsvp_response)/sizeof(rsvp_response[0]);
    // array
    for(int i = 0; i < sizeOfArray; i++){
        std::cout << rsvp_response[i] << std::endl; 
    }
    cout << endl << endl;
    cout << "PRINTING FROM VECTOR []" << endl; 
    // vector
    for (int i = 0; i < responded_yes.size(); i++){
        std::cout << responded_yes[i] << std::endl; 
    }

    cout << endl << endl; 
    cout << "PRINTING FROM VECTOR.AT(#)" << endl; 
    // vector
    for (int i = 0; i < responded_yes.size(); i++){
        std::cout << responded_yes.at(i) << std::endl; 
    }
}