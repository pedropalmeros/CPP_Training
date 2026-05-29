#include <iostream> 
using namespace std; 

struct A {A() { cout << "A()\n";}};

struct B : public A{ B(){cout << "B()\n"; }};

struct C : public A{ C(){cout << "C()\n"; }}; 

struct D : public B, public C { D(){cout << "D()\n";}};

int main(){
    D d;
}