#include <iostream> 

using namespace std; 

enum ANIMALS{MAMMAL, DOG, CAT};

const int NumberKindAnimals = 3;

class Mammal{
    protected:
        int lAge;
    public:
        Mammal():lAge(1){ 
            cout << "MAMMAL CONSTRUCTOR " << endl; 
        }

        virtual ~Mammal(){
            cout << "MAMMAL DESTRUCTOR" << endl; 
        }

        Mammal(const Mammal & rhs); // Copy constructor with reference.

        virtual void Talk() const{
            cout << "MAMMAL TALKING .... "  << endl; 
        }

        virtual Mammal * Clone(){
            return new Mammal(*this); /// this calls to the copy constructor with reference.
        }
    
        int getAge() const{
            return this->lAge;
        }
};

Mammal::Mammal(const Mammal &rhs):lAge(rhs.getAge()){
    cout << "COPY CONSTRUCTOR WITH REFERENCE" << endl; 
}

class Dog : public Mammal{
    public:
        Dog(){
            cout << "CONSTRUCTOR --- DOG " << endl;         
        }
        virtual ~Dog(){
            cout << "DESTRUCTOR --- DOG" << endl; 
        }
        Dog(const Dog &rhs);
    
        void Talk() const{
            cout << "TALK --- DOG"  << endl;
        }
    
        virtual Mammal * Clone(){
            return new Dog(*this);
        }
};

Dog::Dog(const Dog &rhs):Mammal(rhs){
    cout << "COPY CONSTRUCTOR OF DOG.... "  << endl; 
}


class Cat : public Mammal{
    public:
        Cat(){
            cout << "CONSTRUCTOR *** CAT" << endl; 
        }

        virtual ~Cat(){
            cout << "VIRTUAL DESTRUCTOR *** CAT " << endl; 
        }

        Cat(const Cat & rhs); /// COPY CONSTRUCTOR OF CAT

        void Talk() const{
            cout << "TALK **** CAT" << endl;
        }

        virtual Mammal * Clone(){
            return new Cat(*this);
        }
};

Cat::Cat(const Cat &rhs):Mammal(rhs){
    cout << "COPY CONSTRUCTOR OF CAT .... "  << endl; 
}


int main(){
    Mammal * mammalArray[NumberKindAnimals];
    Mammal *ptr; 
    int option, i; 

    for (i=0; i < NumberKindAnimals; i++){
        cout << "| (1) DOG   | (2) CAT   | (3) MAMMAL   |:  ";
        cin >> option;

        switch(option){
            case 1:
                ptr = new Dog();
                break;
            
            case 2:
                ptr = new Cat();
                break;
            
            case 3:
                ptr = new Mammal;
                break;
        }
        mammalArray[i] = ptr;
    }

    Mammal *otherArray[NumberKindAnimals];
    for(i = 0; i < NumberKindAnimals; i++){
        mammalArray[i]->Talk(); 
        otherArray[i] = mammalArray[i]->Clone(); 
    }

    for(i = 0; i < NumberKindAnimals; i++){
        otherArray[i]->Talk();
    }

    return 0; 
}