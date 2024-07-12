/***************************************************************************************************************************************************
 * C++ exteds the polimorfism to allows the pointers of a base class to point to a derived class
 * Mammal * ptrMammal = new Dog;
 * In the previous line the pointer is Mammals type but it is pointing to a Dog object. 
 * 
 * VIRTUAL Methods are used almost as a template THEY HAVE TO BE OVERLOADED IN THE DERIVED CLASSES
 *************************************************************************************************************************************************/
#include <iostream>

using namespace std; 

class Mammal{
    protected:
        int lAge; 

    public:
        Mammal():lAge(1){
            cout << "CONSTRUCTOR ----- MAMMMAL" << endl; 
        }
        virtual ~Mammal(){
            cout << "DESTRUCTOR ------ MAMMAL" << endl;
        }
        void Move()const{
            cout << "MOVING ONE STEP ------ MAMMAL"  << endl; 
        }
        virtual void Talk() const{
            cout << "TALKING -------- MAMMAL" << endl;
        }
};

class Dog : public Mammal{
    public:
        Dog(){
            cout << "CONSTRUCTOR ******* DOG" << endl; 
        }

        virtual ~Dog(){
            cout << "DESTRUCTOR *********** DOG" << endl;
        }

        void moveTail(){
            cout << "MOVING TAIL ************** DOG " << endl; 
        }

        void Talk()const{
            cout << "BARKKKINNNNGGG **************** DOG " << endl;
        }

        void Move()const{
            cout << "MOVING ONE STEP ************* DOG" << endl; 
        }

};

int main(){
    Mammal * ptrDog = new Dog;

    ptrDog->Move();
    ptrDog->Talk();

    return 0;
}