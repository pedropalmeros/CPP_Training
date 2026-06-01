#include <iostream>

using namespace std; 

// Abstract base (interface)
struct Widget{
    virtual void draw() const = 0; // pure virtual -> abstract
    virtual ~Widget() = default; 
};

// Concrete implementations
struct Button : Widget {
    void draw() const override { cout << "Button\n";}
};

struct Slider : Widget{
    void draw() const override { cout << "Slider\n";}
};

int main(){
    // widget w; // Uncomment to se: error - 'Widget' is abstract
    Button b; 
    Slider s; 

    // Runtime polymorphism via base pointer
    const Widget* w = &b; ; 
    w->draw();          // -> Button
    w = &s;      
    w->draw();          // -> Slider
}