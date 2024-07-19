#include <iostream>

using namespace std; 

int main(){
    char buffer[80];
    cout << "Wrrite the chain: " << endl; 
    cin.get(buffer,79); 
    cout << "Here is the buffer: " << buffer << endl;
}