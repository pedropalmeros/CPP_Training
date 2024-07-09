#include <iostream>

using namespace std; 

class Counter{
    private:
        int lVal;
    public:
        Counter();
        Counter(int initialValue);
        ~Counter();
        int getVal() const; 
        void setVal(int aVal); 
        Counter Adding(const Counter &);
};

Counter::Counter(){}

Counter::Counter(int initialValue):lVal(initialValue){}

Counter::~Counter(){}

int Counter::getVal() const{
    return lVal;
}

void Counter::setVal(int aVal){
    lVal = aVal;
}

Counter Counter::Adding(const Counter & rhs){
    return Counter(lVal+rhs.getVal());
}

int main(){
    Counter varOne(2), varTwo(4), varThree;

    varThree = varOne.Adding(varTwo);

    cout << "vareOne: " << varOne.getVal() << endl; 
    cout << "varTwo: " << varTwo.getVal() << endl; 
    cout << "varThree: " << varThree.getVal() << endl; 
    
    return 0; 
}
