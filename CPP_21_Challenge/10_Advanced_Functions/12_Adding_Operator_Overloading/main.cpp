#include <iostream>

using namespace std;

class Counter{
    public:
        Counter();
        Counter(int initialValue);
        ~Counter();
        int getVal() const; 
        void setVal(int aVal); 
        Counter operator+(const Counter &); 
    private:
        int lVal;
};

Counter::Counter(){}

Counter::Counter(int initialValue):lVal(initialValue){}

Counter::~Counter(){}

int Counter::getVal() const{
    return this->lVal;
}

void Counter::setVal(int aVal){
    this->lVal = aVal;
}

Counter Counter::operator+(const Counter &rhs){
    return Counter(lVal + rhs.getVal());
}

int main(){
    Counter varOne(21), varTwo(6), varThree;

    varThree = varOne + varTwo; 

    cout << "varOne: " << varOne.getVal() << endl; 
    cout << "vatTwo: " << varTwo.getVal() << endl;
    cout << "varThree: " << varThree.getVal() << endl; 

    return 0; 
}