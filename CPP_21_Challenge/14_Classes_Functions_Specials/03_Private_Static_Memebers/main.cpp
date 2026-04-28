#include <iostream>

using namespace std; 

class Cat{
    private:
        int lAge; 
        static int CatsNumber;
    public:
        Cat(int aAge):lAge(aAge){CatsNumber++;}
        virtual ~Cat() {CatsNumber--;}
        virtual int getAge(){return lAge;}
        virtual void setAge(int aAge){lAge = aAge;}
        virtual int getQuantity(){ return CatsNumber;}
};

int Cat::CatsNumber = 0;

int main(){
    const int MaxCats = 5; 

    Cat *CatsHouse[MaxCats]; 
    for(int i = 0; i<MaxCats; i++){
        CatsHouse[i] = new Cat(i); 
    }

    for(int i = 0; i <MaxCats; i++){
        cout << "!Quedan : ";
        cout << CatsHouse[i]->getQuantity();
        cout << " cats! \n"; 
        cout << "Se va a eliminar el que tiene: ";
        cout << CatsHouse[i]->getAge()+2; 
        cout << " anios de edad\n";
        delete CatsHouse[i];
        CatsHouse[i] = 0; 
    }
    return 0;
}