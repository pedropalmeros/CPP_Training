#include <iostream> 

using namespace std; 

class Cat{
    private:
        int lWeight;
        int lAge;
    public:
        Cat():lWeight(5),lAge(1){}
        ~Cat(){}
        int getAge() const{ return this->lAge;}
        void setAge(int aAge){lAge = aAge;}
        int getWeight()const{return this->lWeight;}
        void setWeight(int aWeight){lWeight = aWeight;}
};

int main(){
    Cat * Family[500]; 
    int i;
    Cat *apCat; 
    for(i = 0; i< 500; i++){
        apCat = new Cat; 
        apCat->setAge(2*i+1);
        Family[i] = apCat;
    }

    for(i = 0; i<500; i++){
        cout << "Cat " << i+1 << ": " << Family[i]->getAge() << ". " << endl; 
    }
}