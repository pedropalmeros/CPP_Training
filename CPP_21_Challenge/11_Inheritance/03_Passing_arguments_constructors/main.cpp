#include "dog.hpp"

int main(){
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6,8);
    Dog Dobbie(3, 10, DOBERMAN);

    Fido.talk();
    Fido.moveTail();


    cout << "DESCRIBING FIDO: " << endl; 
    Fido.getAllInfo();
    cout << "-------------------------" << endl; 

    cout << "DESCRIBING ROVER: " << endl; 
    Rover.getAllInfo();
    cout << "-------------------------" << endl; 


    cout << "DESCRIBING BUSTER: " << endl; 
    Buster.getAllInfo();
    cout << "-------------------------" << endl;


    cout << "DESCRIBING DOBBBIE: " << endl; 
    Dobbie.getAllInfo();
    cout << "-------------------------" << endl; 





    cout << "Fido is: " << Fido.getAge() << " years old." << endl; 
    return 0; 
}