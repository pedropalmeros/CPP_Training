#include "dog.hpp"

Dog::Dog():lRaza(GOLDEN){
    cout << "DOG CONSTRUCTOR" << endl; 
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
