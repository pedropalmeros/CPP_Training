/*******************************************************************************************************************
 * DYNAMIC CAST - RTTI 
 *******************************************************************************************************************/

#include <iostream>

using namespace std; 

enum TYPE {HORSE, PEGASUS};

class Horse{
    private:
        int lAge;
    public:
        virtual void Gallop() {
            cout << "Galloping " << endl;
         }
};

class Pegasus : public Horse{
    public: 
        virtual void Fly() { cout <<  "I can fly, I can fly"<< endl; }
};

const int HorseNumbers = 5; 

int main(){
    Horse * Ranch[HorseNumbers];
    Horse * ptrHorse; 

    int option, i; 
    for( i =0; i < HorseNumbers; i++ ){
        cout << "(1) Horse      (2) Pegasus: ";
        cin >> option;
        if (option ==1){
            ptrHorse = new Horse; 
        }
        else 
            ptrHorse = new Pegasus;
        
        Ranch[i] = ptrHorse;
    }

    for (i = 0; i < HorseNumbers; i++){
        Pegasus *ptrPegasus = dynamic_cast<Pegasus *>(Ranch[i]);
        if (ptrPegasus)
            ptrPegasus->Fly();
        else 
            cout << "A Simple Horse"<< endl; 
    }

    return 0; 
}