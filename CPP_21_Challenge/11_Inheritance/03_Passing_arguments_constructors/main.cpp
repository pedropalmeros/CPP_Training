#include "dog.hpp"

int main(){
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6,8);
    Dog Dobbie(3, 10, DOBERMAN);

    Fido.talk();
    Fido.moveTail();

    cout << "Fido is: " << Fido.getAge() << " years old." << endl; 
    return 0; 
}