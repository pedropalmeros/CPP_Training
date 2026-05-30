#include <iostream>
using namespace std; 

struct A { A() { cout << "A()\n"; }};

// Share a single A via virtual inheritance
struct B : virtual public A { B() { cout << "B()\n"; }};
struct C : virtual public A { C() { cout << "C()\n"; }};

struct D : public B, public C{
    // Most-dervied constructs the virtual base:
    D() : A(){cout <<"D()\n"; }

    /**
     * Note that in this constructor A() is explicitly invoked.
     * In virtual inheritance the most-derived class is responsible
     * of constructing the shared base.
     */
    
};

int main(){
    D d; // Prints: A(), B(), C(), D() <- A () once
}