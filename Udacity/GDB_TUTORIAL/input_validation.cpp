#include <iostream> 

using namespace std; 

int main(){
    int num = 0; 
    cout << "Enter a number between 1 - 10: "; 
    cin >> num; 
    if(num > 0 && num <= 10){
        cout << "Input accepted! " << endl; 
    }
    else{
        cout << "Error: number must be between 1 - 10."
        << endl; 

        return 1;
    }
    return 0; 
}