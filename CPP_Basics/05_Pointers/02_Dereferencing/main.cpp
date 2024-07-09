#include <iostream> 

using namespace std; 

int main(){
    // this is an integer variable with value = 54
    int a = 54; 

    // this is a pinter that holds the address of the variable 'a'.
    // if 'a' was a float, rather than int, so should be its pointer. 

    int * pointerToA = &a; 

    // If we were to print pointerToA, we'd obtain the address of 'a'; 
    cout << "pointerToA stores "  << pointerToA << endl; 

    // If we want to know that is stored in this address, we can dereference pointerToA
    cout << "pointerToA points to " << *pointerToA << endl; 
}