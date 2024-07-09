#include <iostream>
#include <string>

using namespace std; 

class Dog{
    private:
        string name; 
        long licence;
    
    public:
        void setName(string inName);
        void setLicence(long inLicence);
        string getName();
        long getLicence();
        void describe();
};

void Dog::setName(string inName){
    name = inName;
}

void Dog::setLicence(long inLicence){
    licence = inLicence;
}

string Dog::getName(){
    return name;
}

long Dog::getLicence(){
    return licence;
}

void Dog::describe(){
    cout << name  << " licence is : " << licence << endl; 
}