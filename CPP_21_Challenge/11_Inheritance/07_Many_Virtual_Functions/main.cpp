/************************************************************************************************
 * NOTE: When a method is marked as virtual, if it is redefined in the derived classes, it keeps being virtual.
 * It is a good practice to continuing marking it as virtual, just to make the things clearer.
 ************************************************************************************************/

#include <iostream>

using namespace std; 

class Mammal{
    public:
        Mammal():lAge(1){}
        virtual ~Mammal(){}
        virtual void Talk() const{
            cout << "MAMMAL --- TALK" << endl; 
        }

    protected:
        int lAge; 
};

class Dog : public Mammal{
    public:
        void Talk() const{
            cout << "DOG --- TALK" << endl; 
        }
};

class Cat : public Mammal{
    public:
        void Talk() const{
            cout << "Cat --- TALK" << endl; 
        }
};

class Horse : public Mammal{
    public:
        void Talk() const{
            cout << "Horse --- TALK" << endl; 
        }
};

class Pig : public Mammal{
    public:
        void Talk() const{
            cout << "Pig --- TALK" << endl; 
        }
};

int main(){
    Mammal * animalArr[5];
    Mammal * ptrMammal;

    int option;

    for( int i = 0; i < 5 ; i++){
        cout << "Introduce a number: (1)Dog (2)Cat (3)Horse (4)Pig: ";
        cin >> option;

        switch(option){
            case 1:
                ptrMammal = new Dog; 
                break;
            case 2:
                ptrMammal = new Cat;
                break;
            case 3: 
                ptrMammal = new Horse;
                break;
            case 4:
                ptrMammal = new Pig;
                break;
            default:
                ptrMammal = new Mammal;
        }
        animalArr[i] = ptrMammal;
    }
    for (int i = 0; i < 5; i++){
        animalArr[i]->Talk();
    }

    return 0;
}