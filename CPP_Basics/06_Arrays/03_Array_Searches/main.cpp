/**********************************************************************************
 * Goal: practice sarching an array in C++
 * Tehre is an array of integers. The lenght of the arrays to be searched
 * varies. A user will enter an integer and the rpgroam will search the array. 
 * If the value is in the array, the program will return thelocation of
 * the element. If the value is not in the array, the user will be notified
 * that the value is not in the array. To exit the rpogram the user will enter -1
 **********************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std; 

int main(){
    int searchArray[10] = {324, 4567, 6789, 5421345, 7, 65, 8965, 12, 342, 485};   
    // searchkey - number to be found
    // location - array index of the found value
    int searchKey;
    int location = -1;
    bool found = false;

    // TODO: write code to determine if integers entered by
    // the user are in searchArray

    cout << "Introuce the number to be found: " << endl; 
    cin >> searchKey;

    for (int i=0; i<10; i++){
        if (searchKey == searchArray[i]){
            location = i+1; 
            found = true;
            break;
        }
    }

    // Use these commands to give feedback to the user
    if(location != -1){
        cout << searchKey << " is at location " << location << " in the array. " << endl<< endl;
    }
    else{
        cout << searchKey << " is not in the array.\n"  << endl; 
    }

    return 0;
}
