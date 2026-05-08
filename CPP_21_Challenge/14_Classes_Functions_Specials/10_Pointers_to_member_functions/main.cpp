#include <iostream> 

using namespace std; 

class Mamifero{
    protected:
        int suEdad;
    public:
        Mamifero():suEdad(1){}
        virtual ~Mamifero(){}; 
        virtual void Hablar() const = 0; 
        virtual void Mover() const = 0; 
};

class Perro : public Mamifero{
    public: 
        virtual void Hablar() const { cout << "Guauuuuu \n"; }
        virtual void Mover() const { cout << "Caminando hacia el amo .... \n";}
};

class Gato : public Mamifero{
    public:
        virtual void Hablar() const { cout << "Miauuuuuuu\n";}
        virtual void Mover() const { cout << "Caminando sigilosamente..... \n";}
};

class Caballo : public Mamifero{
    public:
        virtual void Hablar() const { cout << "Yihiiiiiiii\n"; }
        virtual void Mover() const { cout << "Galopando.....\n"; }
};

int main(){
    void (Mamifero::*apFunc)() const = 0; 
    Mamifero* aptr = NULL;
    int Animal; 
    int Metodo; 
    bool fSalir = false; 

    while(!fSalir){
        cout << "(0)Salir  |  (1)Perro  |  (2)Gato  |  (3)Caballo  | : ";
        cin >> Animal; 

        switch(Animal){
            case 1: aptr = new Perro; break; 
            case 2: aptr = new Gato; break; 
            case 3: aptr = new Caballo; break; 
            default: fSalir = true; break;
        }

        if(fSalir)
            break; 
        
            cout << "(1)Hablar   |   (2)Mover: "; 
            cin >> Metodo; 
            switch(Metodo){
                case 1: aptr->Hablar(); break; 
                case 2:
                default: aptr->Mover(); break; 
            }


    }

    (aptr->*apFunc)();
    delete aptr; 
    
    return 0; 
}