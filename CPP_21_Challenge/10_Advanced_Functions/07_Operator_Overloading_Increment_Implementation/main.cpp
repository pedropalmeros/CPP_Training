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
        void operator++();
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
    lVal += 1; 
}

void Counter::operator++(){
    lVal+=1;
}

int main(){
    Counter i; 
    cout << "The value of 'i' is: " << i.getVal() << endl; 
    i.increment();
    cout << "The value of 'i' is: " << i.getVal() << endl; 
    ++i; 
    cout << "The value of 'i' is: " << i.getVal() << endl; 
    return 0;
}

/*************************************************************************************
 * there is an important deffect in the approach used in the previous example 
 * If we would like to code 
 * a = ++i; 
 * this will fail since ++i does not return anything. 
 *************************************************************************************/