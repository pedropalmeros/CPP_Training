#include <iostream> 

using namespace std; 

class ComplexNumber{
    private: 
        double real; 
        double complex; 
    public: 
        ComplexNumber(double real, double complex):real(real),complex(complex){}
        ComplexNumber():real(0),complex(0){}
        
        double getReal() const{ return this->real;}
        double getComplex() const {return this->complex;}

        void setReal(double value){
            real = value; 
        }

        void setComplex(double value){
            complex = value; 
        }

        ComplexNumber Add(const ComplexNumber &);

        ComplexNumber operator+(const ComplexNumber &);

        void printNumber();
};

ComplexNumber ComplexNumber::Add(const ComplexNumber &rhs){
    double realSum = this->real + rhs.getReal(); 
    double complexSum = this->complex + rhs.getComplex(); 
    
    return ComplexNumber(realSum,complexSum); 
}

void ComplexNumber::printNumber(){
    cout << "ComplexNumber---> Real: " << getReal() << "     Complex: "  << getComplex() << endl; 
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &rhs){
    double realSum = this->real + rhs.getReal(); 
    double complexSum = this->complex + rhs.getComplex(); 
    
    return ComplexNumber(realSum,complexSum); 
}


int main(void){
    ComplexNumber complex1(1,3); 
    ComplexNumber complex2(4,5); 
    ComplexNumber complex3; 

    complex1.printNumber(); 
    complex2.printNumber(); 
    complex3.printNumber(); 

    complex3 = complex1.Add(complex2); 

    cout << "complex3 after the addition: " << endl; 
        complex3.printNumber(); 

    ComplexNumber complex4 = complex1 + complex3;
    complex4.printNumber();

    
}