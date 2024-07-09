/************************************************************************************
 *  For this program print for each variable
 *  print the value of the variable
 * then print the address where it is stored
*************************************************************************************/

#include <iostream>
#include <string>

using namespace std; 

int main(){
    // VARIABLE DECLARATION
    int  givenInt = 55; 
    float givenFloat = 9.3;
    double givenDouble = 13.5; 
    string givenString = "Hola" ;
    char givenChar = 'b';

    // DECLARING POINTERS
    int *ptr2Int = &givenInt; 
    float *ptr2Float = &givenFloat;
    double *ptr2Double = &givenDouble;
    string *ptr2String = &givenString; 
    char *ptr2Char = &givenChar;


    // PRINTING THE ADDREESS OF EACH POINTER
    cout << givenInt << &givenInt << endl; 
    cout << givenFloat << &givenFloat << endl;
    cout << givenDouble << &givenDouble << endl;
    cout << givenString << &givenString  << endl; 
    cout << givenChar << &givenChar << endl; 

    // PRINTING WHAT LIVES IN THE POINTERS
    cout << *ptr2Int << endl;
    cout << *ptr2Float << endl; 
    cout << *ptr2Double << endl; 
    cout << *ptr2String << endl; 
    cout << *ptr2Char << endl; 

    return 0;

}