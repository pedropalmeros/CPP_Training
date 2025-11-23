#include <iostream>

using namespace std; 

class Counter{
    private:
        int lVal; 
    public:
        Counter();
        ~Counter();
        void increment();
        int getVal();
        void setVal(int aVal);

};

Counter::Counter():lVal(0){}

Counter::~Counter(){}

int Counter::getVal(){
    return lVal;
}

void Counter::setVal(int aVal){
    lVal = aVal;
}

void Counter::increment(){
    ++lVal; 
}


int main(){
    Counter i; 
    cout << "The value of 'i' is: " << i.getVal() << endl; 
    i.increment();
    cout << "The value of 'i' is: " << i.getVal() << endl; 
}