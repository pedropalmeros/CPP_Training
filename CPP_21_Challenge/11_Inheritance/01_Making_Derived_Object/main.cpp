/*********************************************************************
 * THE TRICK OF A GOOD DESIGN is to represent the importance aereas
 * in such a way that it looks like the reality. 
 * 
 * COMPARISON BETWEEN PROTECTED AND PRIVATE
 * PRIVATE members are not available for derived classes. 
 * PROTECTED members are avilable ONLY for the derived classes.
 *********************************************************************/

#include <iostream> 

using namespace std; 

enum RAZA { GOLDEN, CAIRN, DANDIE, SHEETLAND, DOBERMAN, LAB};

class Mammal{
    public:
        //constructor
        Mammal(){}
        ~Mammal(){}

        //access methods
        int getAge() const; 
        void setAge(int);
        int getWeight() const; 
        void setWeight(int); 

        // Other methods
        void Talk() const;
        void Sleep() const; 

    protected:
        int lAge; 
        int lWeight; 
};

int Mammal::getAge() const{
    return lAge; 
}

void Mammal::setAge(int aAge){
    lAge = aAge; 
}

int Mammal::getWeight() const{
    return lWeight; 
}

void Mammal::setWeight(int aWeight){
    lWeight = aWeight;
}

void Mammal::Talk()const{
    cout << "MAMMAL TALKING" << endl; 
}

void Mammal::Sleep()const{
    cout << "MAMMAL SLEEPING" << endl;
}

class Dog : public Mammal{
    public: 
        // Constructors
        Dog(){}
        ~Dog(){}

        // Access Methods. 
        RAZA getRaza() const; 
        void setRaza (RAZA aRaza); 

        // Other methods.
        void moveTail(); 
        void askFood(); 
    private:
        RAZA lRaza;
};

RAZA Dog::getRaza()const{
    return lRaza;
}

void Dog::setRaza(RAZA aRaza){
    lRaza = aRaza;
}


int main(){
    Dog fido;
    fido.Talk(); 
    cout << "Fido is: " << fido.getAge() << " years old." << endl; 
    
    return 0; 
}
