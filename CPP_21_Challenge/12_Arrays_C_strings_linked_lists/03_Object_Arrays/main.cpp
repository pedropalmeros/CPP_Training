#include <iostream> 

using namespace std; 

class Cat{
    private:
        int lWeight;
        int lAge;
    public:
        Cat():lWeight(5),lAge(1){}
        ~Cat(){}
        int getAge()const{return lAge;}
        void setAge(int aAge){lAge = aAge;}
        int getWeight()const{return lWeight;}
        void setWeight(int aWeight){lWeight = aWeight;}
};

int main(){
    Cat Camada[5];
    int i;

    for(i=0; i<5; i++){
        Camada[i].setAge(2*i + 1);
    }

    for(i=0; i<5; i++){
        cout <<"Cat #" << i+1 <<  " is : " << Camada[i].getAge() <<  " years old." << endl; 
    }
    
    return 0;
}
