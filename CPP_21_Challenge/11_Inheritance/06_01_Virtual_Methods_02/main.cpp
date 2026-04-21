#include <iostream> 

using namespace std; 

class  Vehiculo{
    public:
        virtual void encender(){
            cout << "Encendiendo el vehiculo generico" << endl;
        }
};

class Auto : public Vehiculo{
    public:
        void encender(){
            cout << "Encendiendo auto\n";
        }
};

int main(){
    Vehiculo* v = new Auto(); 
    v->encender();
}