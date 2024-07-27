#include <iostream> 

using namespace std; 

typedef int SPANS;

enum COLOR{Red, Green, Blue, Yellow, White, Black, Brown};

class Horse{
    public:
        Horse(COLOR aColor, SPANS aHeight);
        virtual ~Horse(){cout << "HORSE constructor ...." << endl; }
        virtual void Neight() const {cout <<"HORSE Neighting..." << endl;}
        virtual SPANS getHeight() const{return lHeight;}
        virtual COLOR getColor() const {return lColor;}
    private:
        SPANS lHeight; 
        COLOR lColor;
};

Horse::Horse(COLOR aColor, SPANS aHeight):lColor(aColor),lHeight(aHeight){
    cout << "HORSE Constructor" << endl; 
}

class Bird{
    private: 
        COLOR lColor; 
        bool lMigrate;
    public:
        Bird(COLOR aColor, bool lMigrate);
        virtual ~Bird(){cout << "BIRD Destructor"<< endl; }
        virtual void Chirp() const {cout << "BIRD Chirping" << endl; }
        virtual void Fly()const {cout << "BIRD Flying" << endl; }
        virtual COLOR getColor() const {return lColor;}
        virtual bool getMigration() const {return lMigrate;}
};

Bird::Bird(COLOR aColor, bool aMigrate):lColor(aColor), lMigrate(aMigrate){
    cout << "BIRD Constructor" << endl; 
}

class Pegasus:public Horse, public Bird{
    private: 
        long NoBelievers;
    
    public:
        Pegasus(COLOR, SPANS, bool, long);
        ~Pegasus(){cout << "PEGASUS destructor" << endl;}
        void Chirp() const {Neight();}; 
        virtual long getNoBelievers()const{return NoBelievers;}
};

Pegasus::Pegasus(COLOR aColor, SPANS aHeight, bool aMigrate, long aNoBelievers):
Horse(aColor, aHeight),
Bird(aColor,aMigrate),
NoBelievers(aNoBelievers){
    cout << "CONSTRUCTOR - PEGASUS" << endl; 
}

int main(){
    Pegasus *ptrPegasus = new Pegasus(Red, 5, true, 10);
    ptrPegasus->Fly();
    ptrPegasus->Neight();
    cout << endl << "Pegasus measures: " << ptrPegasus->getHeight();
    cout << " spans of height"<< endl; 
    if (ptrPegasus->getMigration())
        cout << "Pegasus Migrate" << endl; 
    else
        cout << "Pegasus do not migrate" << endl; 
    cout << ptrPegasus->getNoBelievers() << " believe that it exists." << endl; 
}