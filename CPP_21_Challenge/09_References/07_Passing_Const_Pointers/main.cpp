#include <iostream> 

using namespace std; 

class SimpleCat{
    public:
        SimpleCat();
        SimpleCat(SimpleCat &);
        ~SimpleCat();
        int getAge() const; 
        void setAge(int age);
    private:
        int lAge;
};

SimpleCat::SimpleCat(){
    cout << "GENERIC CONSTRUCTOR of SIMPLECAT" << endl;
    this->lAge = 1; 
}


SimpleCat::~SimpleCat(){
    cout  << "DSESCTRUCTOR of SimpleCat" << endl;
}

void SimpleCat::setAge(int age){
    this->lAge = age;
}

int SimpleCat::getAge() const{
    return this->lAge;
}


const SimpleCat * const FunctionTwo(const SimpleCat  * const daCat);

int main(){
    cout << "Create a cat..." << endl; 
    SimpleCat Pelusa;
    cout << "Pelusa is "  << Pelusa.getAge() << " years old." <<  endl; 

    int age = 5; 

    Pelusa.setAge(age);

    cout << "Pelusa is "  << Pelusa.getAge() << " years old." << endl; 
    cout << "Calling to FunctionTwo ... " << endl; 
    
    FunctionTwo(&Pelusa);
    cout << "Pelusa is " << Pelusa.getAge() << " years old." << endl; 

    return 0;
}

// FunctionTwo pass a const pointer
// This function returns a constant pointer to a constant object
const SimpleCat * const FunctionTwo(const SimpleCat * const theCat){
    cout << "Function Two ... Going back ... " <<endl; 
    cout << "Pelusa is " << theCat->getAge() << " years old." << endl; 
    //theCat->setAge(8); // If this line in uncommented it will break since it is a constant pointer,
                         // In this case the theCat cannot be change neither the pointer can change.
    cout << "EXITING Function Two" << endl; 
    return theCat;  
}
