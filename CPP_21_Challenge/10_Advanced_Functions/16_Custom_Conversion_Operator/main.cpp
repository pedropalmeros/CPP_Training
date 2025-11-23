#include <iostream> 

using namespace std; 

class Contador{
private: 
    int suVal;

public: 
    Contador(); 
    Contador(int val);
    ~Contador(){}
    int ObtenerSuVal() const { return suVal;}
    void AsignarSuVal(int x){ suVal = x;}
    operator unsigned short(); 
};


Contador::Contador():suVal(0){}

Contador::Contador(int val): suVal(val){}

Contador::operator unsigned short(){
    return (int(suVal));
}

int main(){
    Contador ctr(5); 
    int elShort = ctr; 

    cout << "elShort: " << elShort << endl; 
    return 0; 
}