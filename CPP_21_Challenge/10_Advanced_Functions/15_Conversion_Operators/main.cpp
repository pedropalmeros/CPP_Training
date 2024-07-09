#include <iostream>

using namespace std;

class Counter{
    public:
        Counter();
        Counter(int val); 
        ~Counter();
        int getVal() const;
        void setVal(int val);
        operator unsigned short();
    private:
        int lVal;
};

Counter::Counter():lVal(0){}

Counter::Counter(int val):lVal(val){}

Counter::~Counter(){}

int Counter::getVal() const{
    return this->lVal;
}

void Counter::setVal(int val){
    lVal = val;
}

Counter::operator unsigned short(){
    cout << "Operator overloading" << endl; 
    return (int(lVal));
}

int main(){
    Counter ctr(5);
    int elShort = ctr; 

    cout << "elShort: " << elShort << endl; 
    return 0;
}


