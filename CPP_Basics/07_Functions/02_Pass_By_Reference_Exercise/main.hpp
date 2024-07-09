#include <iostream>

using namespace std; 

void calculate(float, float, char, float&);
void printEquation(float, float, char, float);

void calculate(float input1, float input2, char operation, float &result){
    switch(operation){
        case '+':
            result = input1  + input2; 
            break;
        case '-':
            result = input1 - input2; 
            break;
        case '*':
            result = input1 * input2; 
            break;
        case '/':
            result = input1 / input2; 
            break;
        default:
            cout << "Illegar operation"  << endl;

    }
}


void printEquation(float input1, float input2, char operation, float result){
    cout << input1 << " " << operation << " " << input2 << " = " << result << endl; 
}
