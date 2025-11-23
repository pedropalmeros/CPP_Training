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
        void increment();
        Counter operator++();
};  

Counter::Counter():lVal(0){}
Counter::~Counter(){}
Counter::Counter(int aVal):lVal(aVal){}
int Counter::getVal()const{
    return lVal; 
}

void Counter::setVal(int aVal){
    lVal = aVal; 
}
 
void Counter::increment(){
    lVal += 1; 
}

Counter Counter::operator++(){
    ++lVal;
    return Counter(lVal);
}

/*void Counter::operator++(){/
    ++lVal;
}*/

int main(){
    Counter i;
    cout << "'i' value: " << i.getVal() << endl;
    i.increment();
    cout << "'i' value: " << i.getVal() << endl;
    Counter a = ++i; 
    cout << "The value of 'a' is: " << a.getVal() << endl; 
    cout << "The value of 'i' is: " << i.getVal() << endl; 
    cout << "Incrementing again i"  << endl; 
    ++i;
    cout << "The value of 'i' is: " << i.getVal() << endl; 
}