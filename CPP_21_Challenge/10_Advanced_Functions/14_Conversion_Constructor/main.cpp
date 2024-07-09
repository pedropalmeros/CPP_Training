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
};

Counter::Counter():lVal(0){}

Counter::Counter(int aVal):lVal(aVal){
    cout << "CALLING THE OVERLOADED CONSTRUCTUR" << endl;
    cout << "CHECK IF THIS HAS BEEN CALLED IN THE CONVERSION" << endl;
}

Counter::~Counter(){}

int Counter::getVal() const{
    return this->lVal;
}

void Counter::setVal(int aVal){
    lVal = aVal;
}

int main(){
    int elShort = 5; 
    Counter elCnt = elShort;
    cout << "elCnt: " << elCnt.getVal() << endl; 
    return 0; 
}
