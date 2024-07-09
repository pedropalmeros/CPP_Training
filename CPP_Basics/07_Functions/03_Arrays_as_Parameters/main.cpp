/**************************************************************************
 * GOAL: Lear to pass arrays  to functions
 **************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

// Pass the array as pointer
void arrayAsPointer(int *array, int size);

// pass the array as a sized array
void arraySized(int array[3], int size);

// Pass the array as unsized array
void arrayUnSized(int array[], int size);

int main(){
    const int size = 3; 
    int array[size] = {33, 66, 99}; 

    // We are passing a pointer or reference to the array
    // so we will not know the size of the array
    // We have to pass the size to the function as well.
    arrayAsPointer(array, size);
    arraySized(array, size);
    arrayUnSized(array, size);
    return 0; 
}

void arrayAsPointer(int *array, int size)
{
    cout << setw(5);
    for(int i=0; i <size; i++){
        cout << array[i] << " ";
    }
    cout << endl; 
}

void arraySized(int *array, int size)
{
    cout << setw(5);
    for(int i=0; i <size; i++){
        cout << array[i] << " ";
    }
    cout << endl; 
}

void arrayUnSized(int *array, int size)
{
    cout << setw(5);
    for(int i=0; i <size; i++){
        cout << array[i] << " ";
    }
    cout << endl; 
}