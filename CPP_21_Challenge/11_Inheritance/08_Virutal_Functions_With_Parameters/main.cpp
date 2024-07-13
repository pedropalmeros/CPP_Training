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

void ValFunc(Mammal);
void ptrFunc(Mammal*);
void refFunc(Mammal &);

int main(){
    Mammal *ptr = NULL;
    int option; 
    while(1){
        bool fExit = false;
        cout << "| (1) Dog   | (2) Cat   | (0) Exit   |" ;
        cin >> option; 
        
        switch(option){
            case 0:
                fExit = true; 
                break;
            case 1:
                ptr = new Dog;
                break;
            case 2:
                ptr = new Cat;
                break;
        }

        if(fExit)
            break;

        ValFunc(*ptr);
        ptrFunc(ptr);
        refFunc(*ptr);

    }

    return 0;
}

void ValFunc(Mammal lMammal){
    lMammal.Talk();
}

void ptrFunc(Mammal* lMammal){
    lMammal->Talk();
}

void refFunc(Mammal &lMammal){
    lMammal.Talk();
}

