#include <iostream> 

using namespace std; 
class Animal{
    public:
        virtual void sound(){ cout << "Some animal sound \n";}
};

class Dog : public Animal{
    public: 
        void sound() override { cout << "Woof!\n";}
};

class Cat : public Animal{
    public:
        void sound() override { cout << "Meow!\n";}
};

int main(){
    Animal* a1 = new Dog(); 
    Animal* a2 = new Dog(); 

    a1->sound(); 
    a2->sound();

    delete a1; 
    delete a2;
}