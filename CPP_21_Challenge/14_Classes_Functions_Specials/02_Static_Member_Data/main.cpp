#include <iostream> 

using namespace std; 

class Cat{
    private:
        int lAge; 
    public:
        Cat(int aAge):lAge(aAge){CatsQuantity++;}
        virtual ~Cat(){ CatsQuantity--;}
        virtual int getAge() {return lAge;}
        virtual void setAge(int aAge){lAge = aAge;}
        static int CatsQuantity;
};

int Cat::CatsQuantity = 0; 

void TelepaticFunction();

int main(){
    const int MaxCats = 5;
    Cat *HouseCats[MaxCats];
    for(int i = 0; i < MaxCats; i++){
        HouseCats[i] = new Cat(i); 
        TelepaticFunction();
    }

    for(int i = 0; i < MaxCats; i++){
        delete HouseCats[i]; 
        TelepaticFunction(); 
    }
    return 0; 
}

void TelepaticFunction(){
    cout << "There are: "; 
    cout << Cat::CatsQuantity << " cats alive\n";
}  