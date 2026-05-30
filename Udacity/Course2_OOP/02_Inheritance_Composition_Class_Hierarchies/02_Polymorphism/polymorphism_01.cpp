#include <iostream> 
using namespace std; 

struct Animal{
    virtual void speak() const { cout << "Animal::speak()\n";}
    virtual ~Animal() { cout << "~Animal()\n";} // virrtual: save via base
};

struct Dog : Animal{
    void speak() const override { cout << "Dog::speak() woff\n";}
    ~Dog(){ cout << "~Dog()\n";}
};

struct Cat : Animal{
    void speak() const override { cout << "Cat::speak() Meow\n";}
    ~Cat() { cout << "~Cat()\n";}
};

void make_noise(const Animal& a){ a.speak(); } // calls correct override

int main(){
    Dog d; Cat c; 

    cout << "--- via base reference ---\n";
    make_noise( d);    // Dog::speak()
    make_noise( c);    // Cat::speak()

    cout << "-- via base pointer + delete --\n"; 
    Animal *p = new Dog(); 
    p->speak(); // Dog::speak(); 
    delete p;   // ~Dog() then ~Animal() because base destructor is virtual
}