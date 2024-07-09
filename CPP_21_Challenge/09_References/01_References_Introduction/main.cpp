/************************************************************************************************************************************************
 * A reference is an alyas or synonim; when a reference is create ti has to be initialized with the name of other object of the same type
 * After initialization the referece works as an alternative name for the variable. and any thing that is done to the reference is done
 * to the original variable.
 ************************************************************************************************************************************************/

#include <iostream> 

using namespace std; 

int main(){
    int intOne; 
    int & ref2intOne = intOne; 

    intOne = 5; 
    cout << "intOne: " << intOne << endl;
    cout << "ref2: " << ref2intOne << endl; 

    ref2intOne = 7; 

    cout << "intOne: " << intOne << endl;
    cout << "ref2: " << ref2intOne << endl;

}