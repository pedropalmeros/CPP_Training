/**************************************************************************
 * GOAL: Create a generic lass.
 * Create a class called Multiplier
 * It multiplies two number -integers
 * or floats
 *******************************************************************/
#include "main.hpp" 

int main(){
    Multiplier<int> multi1;
    Multiplier<float> multi3; 

    int input1, input2; 
    cout << "Introduce the value of the first number (int): " ;
    cin >> input1; 
    cout << "Introduce the value of the second number (int): " ;
    cin >> input2; 
    multi1.setM1(input1);
    multi1.setM2(input2);
    multi1.setProduct();
    multi1.printEquation();

    cout << endl << endl << endl; 

    float input3, input4;
    cout << "Introduce the value of the first number (float): " ;
    cin >> input3; 
    cout << "Introduce the value of the second number (float): " ;
    cin >> input4;
    multi3.setM1(input3);
    multi3.setM2(input4);
    multi3.setProduct();
    multi3.printEquation(); 

    return 0; 

}
