/**************************************************************
 * Goal: Learn to pass variables by reference.
 * Once we learn this, we can modify variables in functions,
 * and the change will be available outside the scope of the 
 * modification
 **************************************************************/

#include <iostream>

void increment(int &input);

using namespace std; 

int main(){
    int a = 34;
    cout << "Before thefunction call a = "<< a << endl; 
    increment(a);
    cout << "After the function call a = "  << a << endl; 
    return 0;
}

void increment(int &input){
    input++;
    cout << " In the function call a = "  << input << endl; 
}