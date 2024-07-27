#include <iostream> 

using namespace std; 

class Horse{
    public: 
        Horse(){ cout << "Horse constructor" << endl; }
        virtual ~Horse() { cout << "Horse destructor" << endl; }
        virtual void Neight()const { cout << "Horse NEIGHTING" << endl; }
};

class Bird{
    public:
        Bird(){ cout << "BIRD constructor "<< endl; }
        virtual ~Bird(){ cout << "BIRD destructor" << endl; }
        virtual void Fly() const{cout << "BIRD Flying" << endl;}
        virtual void Chirp()const{cout << "BIRD Chirping" <<endl;}
};

class Pegasus : public Horse, public Bird{
    public: 
        Pegasus(){cout << "PEGASUS constructor" << endl; }
        ~Pegasus(){cout <<"PEGASUS destructor"<< endl; }
        void Chirp()const{Neight();}
};

const int MagicNumber = 2;

int main(){
    Horse* Ranch[MagicNumber];
    Bird* Aviary[MagicNumber];
    
    Horse *ptrHorse;
    Bird *ptrBird;

    int option,i;

    for(i=0; i<MagicNumber; i++){
        cout << "(1)Horse    (2)Pegasus: ";
        cin >> option;
        if(option==1)
            ptrHorse = new Horse;
        else
            ptrHorse = new Pegasus;
        
        Ranch[i] = ptrHorse;
    }

    for(i=0; i<MagicNumber; i++){
        cout << "(1)Bird    (2)Pegasus: ";
        cin >> option;
        if(option==1)
            ptrBird = new Bird;
        else
            ptrBird = new Pegasus;
        
        Aviary[i] = ptrBird;
    }

    cout << "PRINTING THE RANCH" << endl; 
    for(i=0; i<MagicNumber; i++){
        cout << "Ranch[" << i << "]: ";
        Ranch[i]->Neight();
        cout << endl; 
        delete Ranch[i]; 
    }

    cout << "PRINTING THE AVIARY" << endl; 
    for(i=0; i<MagicNumber; i++){
        cout << "Aviary[" << i << "]: ";
        Aviary[i]->Chirp();
        cout << endl; 
        delete Aviary[i]; 
    }
}