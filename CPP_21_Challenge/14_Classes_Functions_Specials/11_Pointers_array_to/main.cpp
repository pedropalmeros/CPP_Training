#include <iostream>

using namespace std; 

class Perro{
    public:
        void Hablar() const { cout << "Guau\n";}
        void Mover() const { cout << "Caminando hacia el amo \n";}
        void Comer() const { cout << "Comiendo como perro \n";}
        void Grunir() const {cout << "Grrrr \n"; }
        void Gimotear () const { cout << "Gimoteando como perro. \n";}
        void DarVuelta() const { cout << "Dando la vuerta\n"; }
        void HacerMuerto () const { cout << "Haciendo el muerto\n";}
};

typedef void (Perro::*AFM)() const; 

int main(){
    const int MaxFuncs = 7; 
    AFM PerroFunciones[MaxFuncs] = {
        Perro::Hablar,
        Perro::Mover,
        Perro::Comer,
        Perro::Grunir,
        Perro::Gimotear,
        Perro::DarVuelta,
        Perro::HacerMuerto };
    
    Perro* apPerro = NULL; 
    int Metodo; 
    bool fSalir = false; 

    while(!fSalir){
        cout <<"(0)Salir\n(1)Hablar\n(2)Mover\n(3)Comer\n(4)Grunir\n(5)Gimotear\n(6)DarVuelta\n(7)HacerseMuerto\n";
        cout << "Seleccione una opción: ";
        cin >> Metodo;
        if(Metodo == 0){
            fSalir = true;
        }
        else{
            apPerro = new Perro; 
            (apPerro->*PerroFunciones[Metodo-1])();
            delete apPerro;
        }
    }
    return 0; 
}