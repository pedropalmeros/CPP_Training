// inheritance_vs_composition.cpp
#include <iostream>
using namespace std;

struct Engine{
    void start() { cout << "Engine started\n";}
};

// Misuse: "Car is-a Engine" (inheritance)
struct CarInherits : public Engine{
    void drive() { cout << "Car driving\n"; }
};

// Correct: "Car has-a Engine" (composition)
struct CarComposes{
    private:
        Engine engine; 
    public: 
        void start() { 
            engine.start();
            cout << "Car is running\n";
        }
        void drive(){
            cout << "Car driving\n";
        }
};

// A function that works with engines
void service(Engine& e){
    cout << "[Service] "; 
    e.start();
}

int main(){
    cout << "-- Inheritance version (design smell) --\n";
    CarInherits a; 
    a.start(); 
    a.drive(); 
    service(a); 

    cout << "\n-- Composition version (preferred) --\n"; 
    CarComposes b; 
    b.start(); 
    b.drive();
}