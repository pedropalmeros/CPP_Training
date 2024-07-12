#include <iostream> 

using namespace std; 

template <class T>
class Multiplier{
    private:
        T number1;
        T number2; 
        T product;
    public:
        void setM1(T m1); 
        void setM2(T m2);
        void setProduct();
        void printEquation();
};

template<class T>
void Multiplier<T>::setM1(T m1){
    number1 = m1;
}

template<class T>
void Multiplier<T>::setM2(T m2){
    number2 = m2; 
}

template<class T> 
void Multiplier<T>::setProduct(){
    product = number1 * number2;
}

template<class T>
void Multiplier<T>::printEquation(){
    cout << number1 << " * " << number2 << " = " << product << endl; 
}