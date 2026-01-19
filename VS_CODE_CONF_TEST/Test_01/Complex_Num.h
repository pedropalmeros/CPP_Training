#ifndef COMPLEX_NUM_H
#define COMPLEX_NUM_H

#include <iostream> 

using namespace std;

class Complex_Num{
    private:
        double real; 
        double img;

    public:
        Complex_Num(double aReal, double aImg);
        Complex_Num();

        void describeNumber();

};




#endif