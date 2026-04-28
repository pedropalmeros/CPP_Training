#include <iostream> 

using namespace std;

class Gato{
    private:
        int suEdad;
    public:
        Gato(int edad):suEdad(edad){CuantosGatos++;}
        virtual ~Gato(){CuantosGatos--;}
        virtual int ObtenerEdad() {return suEdad;}
        virtual void AsignarEdad(int edad){suEdad = edad;}
        static int CuantosGatos;
};

int Gato::CuantosGatos = 0; 

int main(){
    const int MaxGatos = 5; int i; 
    Gato *CasaGatos[MaxGatos]; 

    for(i=0; i < MaxGatos; i++){
        CasaGatos[i] = new Gato(i); 
    }

    for(i=0; i <MaxGatos; i++){
        cout << "Quedan: " << Gato::CuantosGatos << " gatos!\n"; 
        cout << "Se va a elminar el que tiene: " << CasaGatos[i]->ObtenerEdad(); 
        cout << " anios de edad\n"; 
        delete CasaGatos[i]; 
        CasaGatos[i] = 0;
    }
    return 0;
}