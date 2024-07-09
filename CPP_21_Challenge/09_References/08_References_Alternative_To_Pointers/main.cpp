#include <iostream>

using namespace std; 

class SimpleCat{
    public: 
        SimpleCat();
        SimpleCat(SimpleCat&); // Copy constructor
        ~SimpleCat();
        int getAge() const;
        void setAge(int ); 
    private:
        int Age;
};

SimpleCat::SimpleCat(){
    cout << "GENERIC Constructor of SimpleCat" << endl; 
    this->Age = 1;
}

SimpleCat::SimpleCat(SimpleCat &){
    cout << "COPY Constructor of SimpleCat"  << endl; 
}

SimpleCat::~SimpleCat(){
    cout << "DESTRUCTOR of SimpleCat"  << endl; 
}

int SimpleCat::getAge() const{
    return this->Age;
}

void SimpleCat::setAge(int Age){
    this->Age = Age;
}

const SimpleCat & FunctionTwo(const SimpleCat & theCat); 

int main(){
    cout << "Creating a cat ...." << endl; 
    SimpleCat Pelusa;
    cout << "Pelusa is " << Pelusa.getAge() << " years old." << endl; 

    int age = 5; 
    Pelusa.setAge(age);
    cout << "Pelusa is " << Pelusa.getAge() << " years old." << endl; 

    cout << "MAIN - Calling function two ... "  << endl; 
    cout << "Pelusa is "  << Pelusa.getAge() << " years old."  << endl; 

    return 0;
}

const SimpleCat & FunctionTwo(const SimpleCat & theCat){
    cout << "FUNCTION TWO .... " << endl; 
    cout << "Pelusa is " << theCat.getAge() << " years old." << endl; 
    // theCat.setAge(8); //This is constant, if uncommented it will fail.
    return theCat;
}