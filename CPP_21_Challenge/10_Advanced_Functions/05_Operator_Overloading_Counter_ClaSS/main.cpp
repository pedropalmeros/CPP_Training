#include <iostream> 

using namespace std; 

class Counter{
    private: 
        int lValue;
    
    public:
        Counter();
        ~Counter();
        int getVal() const;
        void setVal(int aVal);
};

Counter::Counter():lValue(0){
    cout << "COUNTER DEFAULT CONSTRUCTOR" << endl; 

}

Counter::~Counter(){
    cout << "COUNTER DEFAULT DESTRUCTOR" << endl;
}

int Counter::getVal() const{
    return this->lValue; 
}

void Counter::setVal(int aVal){
    this->lValue = aVal; 
}

int main(){
    Counter i; 
    cout << "The value of 'i' is " << i.getVal() << endl; 
    return 0; 
}