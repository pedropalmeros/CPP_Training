#include <iostream> 

using namespace std;


class Cat{
    private:
        int lAge;
        static int NumberCats;

    public:
        Cat(int aAge):lAge(aAge){NumberCats++; }
        virtual ~Cat(){NumberCats--;}
        virtual int getAge() {return lAge;}
        virtual void setAge(int aAge){lAge=aAge;}
        static int getNumberCats(){return NumberCats;}
};

int Cat::NumberCats = 0;

void telepaticFunction();

int main(){
    const int MaxCats = 5; 
    Cat *CatHouse[MaxCats]; 
    for(int i =0; i<MaxCats; i++){
        CatHouse[i] = new Cat(i); 
        telepaticFunction(); 
    }

    for(int i = 0; i < MaxCats; i++){
        delete CatHouse[i]; 
        CatHouse[i] = nullptr; 
        telepaticFunction();
    }
    return 0;
}

void telepaticFunction(){
    cout << "There are: " << Cat::getNumberCats() << " cats alive\n";
}