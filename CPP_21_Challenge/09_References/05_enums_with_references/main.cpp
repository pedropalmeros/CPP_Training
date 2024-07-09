#include <iostream>

using namespace std;

typedef unsigned short USHORT;
enum CODIGO_ERR{ EXITO, ERROR};

CODIGO_ERR Factor(USHORT, USHORT &, USHORT &);

int main(){
    USHORT numero, alcuadrado, alcubo;
    CODIGO_ERR result;

    cout << "Introduce a number (0 - 20): ";
    cin >> numero;

    result = Factor(numero,alcuadrado, alcubo);

    if(result==EXITO){
        cout << "Number " << numero << endl; 
        cout << "Power 2 " << alcuadrado << endl; 
        cout << "Power 3 " << alcubo << endl; 
    }
    else
        cout << "ERROR";
    
    return 0;
}

CODIGO_ERR Factor(USHORT n, USHORT & rAlCuadrado, USHORT & rAlCubo){
    if (n > 20){
        return ERROR; 
    }
    else{
        rAlCuadrado = n * n; 
        rAlCubo = n*n*n;
        return EXITO; 
    }
}