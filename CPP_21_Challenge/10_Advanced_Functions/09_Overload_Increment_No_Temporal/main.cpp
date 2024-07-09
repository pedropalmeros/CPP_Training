#include <iostream>

using namespace std;

class Counter{
    private:
        int lVal; 
    public:
        Counter();
        Counter(int aVal);
        ~Counter();
        int getVal() const; 
        void setVal(int aVal);
        const Counter & Counter::operator++();
        void increment();
};

Counter::Counter(){}
Counter::Counter(int aVal):lVal(aVal){}
Counter::~Counter(){}
int Counter::getVal()const {
    return lVal; 
}

void Counter::setVal(int aVal){
    lVal = aVal;
}

const Counter & Counter::operator++(){
    ++lVal;
    return *this; 
}



void Counter::increment(){
    lVal+=1;
}

int main(){
    Counter i;
    cout << "'i' value is: " << i.getVal() << endl;
    i.increment();
    cout << "'i' value is: " << i.getVal() << endl;
    ++i;
    cout << "'i' value is: " << i.getVal() << endl;
    Counter a = ++i; 
    cout << "'a' value is: " << a.getVal() << endl;
    cout << "'i' value is: " << i.getVal() << endl;


}
