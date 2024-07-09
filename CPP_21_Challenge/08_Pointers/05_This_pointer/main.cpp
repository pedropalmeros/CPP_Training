/*************************************************************************************************
 * A class in C++ has a very special pointer "this". The pointer is pointing to the same class. 
 * For me it helps me in the set/get functions to avoid confussions and to be concient that the 
 * attribute or method belongs to the class.
 ************************************************************************************************/

#include <iostream> 
#include "rectangle.hpp"

using namespace std; 

int main(){
    Rectangle Rect;
    cout << "The rectangle is " << Rect.getWidth() << " feets on its width." << endl; 
    cout << "The rectangle is " << Rect.getHeight() << " feets on its height."  << endl; 
    Rect.putWidth(10);
    Rect.putHeight(15);
    cout << "The rectangle is " << Rect.getWidth() << " feets on its width." << endl; 
    cout << "The rectangle is " << Rect.getHeight() << " feets on its height."  << endl; 

    return 0; 
}