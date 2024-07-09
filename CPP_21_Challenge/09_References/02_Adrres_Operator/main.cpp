/***************************************************************************************************************
 * If the address of a reference is obtained and compared with the address of the original variable, 
 * It can be observed that both address are the same, this is the nature and the purpose of the reference
 **************************************************************************************************************/

#include <iostream>

using namespace std; 

int main(){
    int intOne; 
    int & oneRef = intOne; 

    intOne = 5; 
    cout << "intOne: " << intOne << endl; 
    cout << "oneRef: "  << oneRef << endl; 

    cout << "&intOne: "  << &intOne << endl; 
    cout << "&oneRef: "  << &oneRef << endl;

    return 0;
    
}
