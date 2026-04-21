#include "dog.hpp"

int main(){
    Dog Fido;
    Fido.talk();
    Fido.moveTail();

    cout << "Fido is: " << Fido.getAge() << " years old." << endl; 

    cout << "-------------------------" << endl; 
    cout << "Fido talking from DOG CLASS" << endl; 
    Fido.talk();
    cout << "--------------------------" << endl; 
    cout << "Fido talking from MAMMAL CLASS" << endl; 
    Fido.Mammal::talk();
    
    return 0; 
}