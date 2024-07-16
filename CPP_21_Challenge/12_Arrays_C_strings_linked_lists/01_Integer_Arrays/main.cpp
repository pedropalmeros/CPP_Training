#include <iostream>

using namespace std; 

int main(){
    int myArray[5];
    for(int i = 0; i < 5; i++){
        cout << "Introduce a value for myArray[" << i << "]: ";
        cin >> myArray[i]; 
    }
    cout << "The values of the array are: " << endl; 
    for(int i = 0; i < 5; i++){
        cout << "myArray[" << i << "]: " << myArray[i] << endl;
    }

    return 0;

}