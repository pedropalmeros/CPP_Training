#include "dog.hpp"

int main(){
    Dog Fido;
    Fido.talk();
    Fido.moveTail();

    cout << "Fido is: " << Fido.getAge() << " years old." << endl; 
    return 0; 
}