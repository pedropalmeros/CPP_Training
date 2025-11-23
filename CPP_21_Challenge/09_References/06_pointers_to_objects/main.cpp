#include <iostream>

using namespace std; 

class SimpleCat{
    public: 
        SimpleCat();
        SimpleCat(SimpleCat &); // Copy constructor
        ~SimpleCat();
}; 

// constructor default
SimpleCat::SimpleCat(){
    cout << "CONSTRUCTOR SimpleCat"<< endl; 
}

// constructor de copia, recibe puntero una dirección 
SimpleCat::SimpleCat(SimpleCat &){
    cout << "COPY CONSTRUCTOR SimpleCat" << endl; 
}


SimpleCat::~SimpleCat(){
    cout << "DESTRUCTOR SimpleCat" << endl; 
}


SimpleCat FunctionOne(SimpleCat daCat);
SimpleCat * FunctionTwo(SimpleCat *daCat); 

int main(){
    cout << "Create a cat ..." << endl; 
    SimpleCat Pelusa; 
    cout << "Calling to FunctionOne ... "  << endl; 
    FunctionOne(Pelusa);
    cout << "Calling to FunctionTwo..."  << endl; 
    FunctionTwo(&Pelusa);
    return 0;
}

//FunctionOne
SimpleCat FunctionOne(SimpleCat daCat){
    cout << "FunctionOne. Going back..."  << endl; 
    return daCat;
}

//FunctionTwo
SimpleCat*  FunctionTwo(SimpleCat *daCat){
    cout << "Function Two, Comming back ... "  << endl; 
    return daCat;
}