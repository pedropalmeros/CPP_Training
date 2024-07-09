#include <iostream> 

using namespace std; 

class SimpleCat{
    private:
        int itsAge;

    public: 
        SimpleCat();
        ~SimpleCat();
};

SimpleCat::SimpleCat(){
    cout << "Cat constructor has been called" << endl; 
    itsAge = 1; 
}

SimpleCat::~SimpleCat(){
    cout << "Destructor has been called"  << endl; 
}

int main(){
    cout << "SimpleCat pelusa ..... "  << endl; 
    SimpleCat Pelusa; 
    cout << "Creating SimpleCat in the heap" << endl; 
    SimpleCat *Felix = new SimpleCat;
    cout << "delete Felix" << endl; 
    delete Felix; 
    cout << "Exiting the program Pelusa automanage its memory" << endl; 
}