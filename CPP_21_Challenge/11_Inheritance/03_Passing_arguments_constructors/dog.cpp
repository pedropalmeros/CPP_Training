#include "dog.hpp"

Dog::Dog():lRaza(GOLDEN){
    Mammal();
    cout << "DEFAULT DOG CONSTRUCTOR" << endl; 
}

Dog::Dog(int aAge):Mammal(aAge),lRaza(GOLDEN){
    cout << "OVERLOADED 01 DOG CONSTRUCTOR" << endl; 
}

Dog::Dog(int aAge, int aWeight):Mammal(aAge), lRaza(GOLDEN){
    cout << "OVERLOADED 02 DOG CONSTRUCTOR" << endl; 
    lWeight = aWeight;
}

Dog::Dog(int aAge, int aWeight, RAZA aRAZA):Mammal(aAge), lRaza(aRAZA){
    cout << "OVERLOADED 03 DOG CONSTRUCTOR" << endl; 
    lWeight = aWeight;
}

Dog::~Dog(){
    cout << "DOG DESTRUCTOR" << endl; 
}

RAZA Dog::getRaza() const{
    return this->lRaza;
}

void Dog::setRaza(RAZA aRaza){
    lRaza = aRaza;
}

void Dog::moveTail(){
    cout << "DOG -> MOVING THE TAIL" << endl; 
}

void Dog::askFood(){
    cout << "DOG -> BARKIN FOR FOOOOOD" << endl;
}
