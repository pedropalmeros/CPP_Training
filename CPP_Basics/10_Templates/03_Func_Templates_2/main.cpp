/*********************************************************************************************************************************************
 * So far we have looked at functions hwere all the input parameters and return variables are the same type. Now we will look at when the 
 * types are different.
 * 
 * We sill still use the same form, we will just need to tell the compiler that different variable types are allowe. 
 * 
 * -------------EXAMPLE-----------
 * template <typename T, typename U, typename V> 
 * T functionName(u paramter1, V parameter2, .... ){
 * statements
 * }
 *********************************************************************************************************************************************/

#include <iostream>

using namespace std; 

template <typename T, typename U> 
T getBigger(T input1, U input2);

int main(){
    int a = 5; 
    float b = 6.334; 
    int bigger; 
    cout << "Between " << a << " and " << b << " " << getBigger(a,b) << " is bigger." << endl;
    
    cout << "Between " << a << " and " << b << " " << getBigger(b,a) << " is bigger." << endl; 

    return 0;
}

template <typename T, typename U> 
T getBigger(T input1, U input2){
    if (input1 > input2 )
        return input1;
    
    return input2; 
}