/***********************************************
 * Goal: Practice array manipulation in C++
 * The user will input 40 integers.
 * PUt theminto an array. Then print the array in the order the numbers were
 * entered. Then print in reverse order. Then sort the array in ascending order
 * and print it. 
 * The each pirn of the array should separate the numbers in the array by
 * one space.
 * For example: The array were [3,4,55] printout would be 3 4 55
 **********************************************/

#include <iostream>

using namespace std; 

int main(){
    int userInput[40];

    // reading the array
    for(int i = 0; i < 40; i++){
        cout << i+1 << " Introduce a number: ";
        cin >> userInput[i];
    }

    cout << endl << endl; 

    // printing the array as it was populated
    cout << "Printing the array: " << endl << endl; 
    for(int i = 0; i < 40; i++){
        cout << userInput[i]; 
        cout << " ";
    }

    cout << endl << endl; 

    // printing the array in reverse order
    cout << "Printing the array in reverse order: \n\n";
    for(int i = 39;  i >= 0; --i){
        cout << userInput[i]; 
        cout << " "; 
    }

    cout << endl << endl;

    // sorting the array
    for(int i = 0; i < 40; i++){
        for(int j = 0; j< 39-i; j++){
            if(userInput[j] > userInput[j+1]){
                int temp; 
                temp = userInput[j];
                userInput[j] = userInput[j+1];
                userInput[j + 1] = temp;
            }
        }
    }

    // PRINTING THE SORTING ARRAY
    cout << "The array sorted is: " << endl; 
    for(int i = 0; i < 40; i++){
        cout << userInput[i] << " ";
    }
}