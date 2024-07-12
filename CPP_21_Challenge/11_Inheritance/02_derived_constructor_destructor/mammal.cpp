#include "mammal.hpp"

using namespace std; 

Mammal::Mammal():lAge(1),lWeight(50){
    cout << "MAMMAL CONSTRUCTOR" << endl; 
}

Mammal::~Mammal(){
    cout << "MAMMAL DESTRUCTOR" << endl; 
}

// ACCESS METHODS. 
int  Mammal::getAge()const{
    return this->lAge;
}

void Mammal:: setAge(int aAge){
    this->lAge = aAge;
}

int  Mammal::getWeight()const{
    return this->lWeight;
}

void Mammal:: setWeight(int aWeight){
    this->lWeight = aWeight;
}

void Mammal:: talk(){
    cout << "MAMMAL :::: TALK"  << endl; 

}

void Mammal:: sleep(){
    cout << "MAMAL :::: SLEEP"  << endl; 
}
