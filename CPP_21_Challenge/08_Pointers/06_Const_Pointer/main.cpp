/********************************************************************************************************
 * You can use the reserved word const in the pointers, in before and after the type and in both places. 
 * Example
 * const int* pointer1;         || The int value  cannot be changed.
 * int* const pointer2;         || The value can be changed but not the pointer   
 * const int* const pointer3;   || The value cannot be changed, the pointer cannot be changed.
 * "pointer1" is pointing to a constant value, hence the value at which it is pointing cannot be changed. 
 * "pointer2" is a constant pointer. The value of the integer can change but pointer2 cannot point other address
 * "pointer3" is a constant pointer to a constant value, neither both of them can be changed. 
 * 
 */

#include "main.hpp" 

int main(){

    // This pointer can change the value of the Rectangle and can point to other objects if it is required.
    Rectangle * apRect = new Rectangle; 

    // The value of the Rectangle cannot be changed. 
    const Rectangle * apConstRect = new Rectangle();

    // The value of the Rectangle can be changed but no the address of the pointer
    Rectangle * const apConstPointer = new Rectangle();

    cout << "apRect width: " << apRect->getWidth() << " ft. "  << endl; 
    cout << "apConstRect width: " << apConstRect->getWidth() << " ft." << endl; 
    cout << "apConstPointer: "  << apConstPointer->getWidth() << " ft." << endl; 

    apRect->setWidth(20); 
    // apConstRect->setWidth(20); ERROR IF UNCOMMENT. since the rectangle cannot be changed. 
    apConstPointer->setWidth(20);


    cout << "apRect width: " << apRect->getWidth() << " ft. "  << endl; 
    cout << "apConstRect width: " << apConstRect->getWidth() << " ft." << endl; 
    cout << "apConstPointer: "  << apConstPointer->getWidth() << " ft." << endl; 


}