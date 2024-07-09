/**************************************************************************
 * GOAL: Use 'pass by reference' to a function
 * to write this program. 
 * There are two functions that you need to write
 * for this program:
 * calculate(input, input2, operation, result);
 * printEquation(input1, input2, operation, result);
 * Pass by reference any value tat is modified
 * in the function
 * 
 * Put the declaration and definitions of the
 * functions in the header file. 
 **************************************************************************/
#include "main.hpp"

int main(){
    char operation = '*';
    float input1 = 9.8; 
    float input2 = 2.3;
    float result;

    calculate(input1, input2, operation, result); 
    printEquation(input1, input2, operation, result);
    return 0;
}