#include <iostream>

using namespace std; 

class Cat{
    private:
        int *lAge; 
        int *lWeight;
    public:
        Cat();
        ~Cat();
        Cat & operator=(const Cat &); 
        int getAge() const; 
        int getWeight() const; 
        void setAge(int aAge); 
        void setWeight(int aWeight); 
};

Cat::Cat(){
    lAge = new int(3); 
    lWeight = new int(20);
}

Cat::~Cat(){}

int Cat::getAge() const{
    return *lAge;
}

int Cat::getWeight() const{
    return *lWeight;
}

void Cat::setAge(int aAge){
    *lAge = aAge; 
}

void Cat::setWeight(int aWeight){
    *lWeight = aWeight;
}

Cat & Cat::operator=(const Cat & rhs){
    if(this==&rhs){
        return *this;
    }

    *lAge =  rhs.getAge();
    *lWeight = rhs.getWeight();
    return *this;
}

int main(){
    Cat Pelusa; 

    cout << "Pelusa's age: " << Pelusa.getAge() << endl; 
    cout << "Setting Pelusa's age to: 10" << endl; 
    Pelusa.setAge(10);
    cout << "Pelusa's age: " << Pelusa.getAge() << endl; 

    Cat Bigotes;
    cout << "Bigotes' age: " << Bigotes.getAge() << endl; 

    cout << "Copying Pelusa to Bigotes" << endl; 
    Bigotes=Pelusa;

    cout << "Bigotes' age: " << Bigotes.getAge() << endl; 

    Bigotes = Bigotes;

    return 0; 
}