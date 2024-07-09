/*************************************************************************************************
 * Many data members of a class can be located at the heap.
 * Many attributes of the class can be pointing to objects that live in the heap. 
 ************************************************************************************************/

#include <iostream> 

using namespace std; 

class SimpleCat{
    private:
        int *age;       // This is a pointer, the object can be at the heap
        int *weight;    // This is a pointer, the object can be at the heap

    public: 
        SimpleCat();
        ~SimpleCat();

        int getAge();
        void putAge(int); 

        int getWeight(); 
        void putWeight(int);
};

SimpleCat::SimpleCat(){
    /* Since age and weight are pointers a good practice is to initialize them in the constructor*/
    age = new int(2);
    weight = new int(5);
}

SimpleCat::~SimpleCat(){
    /* Since the age and weight live in the heap they should be deleted in the destructor to release memory*/
    delete age; 
    delete weight;
}

int SimpleCat::getAge(){
    return *age;
}

void SimpleCat::putAge(int inAge){
    *age = inAge;
}

int SimpleCat::getWeight(){
    return *weight;
}

void SimpleCat::putWeight(int inWeight){
    *weight = inWeight;
}

int main(){
    SimpleCat *Pelusa = new SimpleCat; 

    cout << "Pelusa is "  << Pelusa->getAge() << " years old."  << endl; 
    Pelusa->putAge(9); 
    cout << "Pelusa is "  << Pelusa->getAge() << " years old."  << endl; 

}