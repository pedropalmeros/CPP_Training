/**********************************************************************************************************************
 * By convention, TO OVERLOAD A POSFIX operatorit is needed to provide an int variable as parameter.
 * The value is ignored, it is just an indication that the operator is posfix.
 *********************************************************************************************************************/
#include <iostream>

using namespace std; 

class Counter{
    private:
        int lVal;
    public:
        Counter();
        ~Counter();
        int getVal() const; 
        void setVal(int aVal); 
        const Counter & operator++(); //prefix
        const Counter operator++(int); //posfix
};
Counter::Counter():lVal(0){}
Counter::~Counter(){}
int Counter::getVal() const{
    return lVal;
}

void Counter::setVal(int aVal){
    lVal = aVal;
}

const Counter & Counter::operator++(){
    ++lVal;
    return *this;
}

const Counter Counter::operator++(int){
    Counter temp(*this);
    ++lVal;
    return temp;
}

int main(){
    Counter i; 
    cout << "'i' value is: " << i.getVal() <<endl; 
    i++;
    cout << "'i' value is: " << i.getVal() <<endl; 
    ++i; 
    cout << "'i' value is: " << i.getVal() <<endl; 
    Counter a = ++i;
    cout << "'a' value is: " << a.getVal() <<endl; 
    cout << "'i' value is: " << i.getVal() <<endl; 
  
    return 0; 
}