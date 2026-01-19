#include <iostream> 
#include "Complex_Num.h"

using namespace std; 

Complex_Num::Complex_Num(double aReal, double aImg){
            real = aReal;
            img = aImg;
        }

 Complex_Num::Complex_Num(){
            real =0.0; 
            img = 0.0;
        }

void Complex_Num::describeNumber(){
            cout << "[DESC A COMPLEX NUMBER]" << endl; 
            cout << "Real: " << real << endl; 
            cout << "Img: " << img << endl; 
            cout << "-----------------------" << endl; 
        }
