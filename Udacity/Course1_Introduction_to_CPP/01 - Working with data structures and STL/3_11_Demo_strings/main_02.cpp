#include <iostream> 
#include <string> 

using namespace std; 

int main(){





    std::string poem = "The quick brown fox jumped over the lazy dog";
    string new_second_half = "galloped under the bridge"; 

    
    int lengthPoem = poem.length(); 
    cout << "The poem is " << lengthPoem << " chars length" << endl; 

    // find the index where jumped is
    std::size_t indexOfJumped = poem.find("jumped"); 
    cout << "Index of Jumped: " << indexOfJumped << endl; 

    string firstHalf = poem.substr(0, indexOfJumped); 

    cout << "First half: " << firstHalf << endl; 

    string new_poem = firstHalf + new_second_half;
    cout << new_poem << endl;

    
}