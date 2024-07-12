#include <iostream>

using namespace std; 

class Mammal{
    public:
        void Move() const;
        void Move(int) const; 
    protected:
        int lAge; 
        int lWeight; 
};

class Dog : public Mammal{
    public:
        void Move()const; 
};

void Mammal::Move()const {
    cout << "MAMMAL MOVING ONE STEP" << endl; 
}

void Mammal::Move(int step) const{
    cout << "MAMMAL MOVING: "  << step << " STEPS" << endl;
}

void Dog::Move()const{
    cout << "DOG MOVING ARROUND" << endl;
}

int main(){
    Mammal BigAnimal; 
    Dog Mercele;

    BigAnimal.Move(2);
    Mercele.Mammal::Move(6);

    return 0;
}