#include <iostream>

using namespace std; 


// ********   PIEZA  *****************
// Clase base abstracta de piezas
class Pieza{
    private:
        int suNumeroPieza;
    public:
        Pieza():suNumeroPieza(1){}
        Pieza(int NumeroPieza):suNumeroPieza(NumeroPieza){}
        virtual ~Pieza(){}
        int ObtenerNumeroPieza() const{
            return suNumeroPieza;
        }
        virtual void Desplegar() const = 0; 
};

// Implementación de una función virtual pura pra que 
// las clases derivadas se puedan encadenar
void Pieza::Desplegar() const{
    cout << "\nNumero de pieza: " << suNumeroPieza << endl;
}

// *************** PIEZA DE AUTO *****************
class PiezaAuto : public Pieza{
    private:
        int suAnioModelo; 
    
    public:
        PiezaAuto() : suAnioModelo(94){}
        PiezaAuto (int anio, int numeroPieza); 
        virtual void Desplegar() const{
            Pieza::Desplegar();
            cout << "Anio del modelo: ";
            cout << suAnioModelo << endl;
        }
};

PiezaAuto::PiezaAuto(int anio, int numeroPieza):suAnioModelo(anio),Pieza(numeroPieza){}

// *********** PIEZA DE AEROPLANO ***************************
class PiezaAeroPlano : public Pieza{
    private:
        int suNumeroMotor;
    public:
        PiezaAeroPlano() : suNumeroMotor(1){};
        PiezaAeroPlano(int NumeroMotor, int NumeroPieza);
        virtual void Desplegar() const{
            Pieza::Desplegar(); 
            cout << "Motor número: "; 
            cout << suNumeroMotor << endl;
        }
};

PiezaAeroPlano::PiezaAeroPlano(int NumeroMotor, int NumeroPieza):
    suNumeroMotor(NumeroMotor),
    Pieza(NumeroPieza){}

// ******************       NODO PIEZA ********************
class NodoPieza{
    private:
        Pieza *suPieza; 
        NodoPieza *suSiguiente; 
    public: 
        NodoPieza(Pieza *);
        ~NodoPieza(); 
        void AsignarSiguiente(NodoPieza * nodo){
            suSiguiente = nodo;
        }
        NodoPieza * ObtenerSiguiente() const; 
        Pieza * ObtenerPieza() const; 
};

// Implementaciones Nodo Pieza
NodoPieza::NodoPieza(Pieza *apPieza):
    suPieza(apPieza),
    suSiguiente(0){}

NodoPieza::~NodoPieza(){
    delete suPieza; 
    suPieza = NULL; 
    delete suSiguiente;
    suSiguiente = NULL;
}

// Regresa NULL si no hay NodoPieza siguiente
NodoPieza * NodoPieza::ObtenerSiguiente() const{
    return suSiguiente;
}

Pieza * NodoPieza::ObtenerPieza() const{
    if (suPieza)
        return suPieza;
    else
        return NULL;
}

// *******************   Lista Piezas ***************************8
class ListaPiezas{
    private:
        NodoPieza * apCabeza; 
        int suCuenta; 
        static ListaPiezas ListaPiezasGlobal;
    public:
        ListaPiezas();
        ~ListaPiezas(); 
        //~necestia constructor de copia y operador igual a 
        void Iterar(void(Pieza::*f)() const) const; 
        Pieza * Encontrar(int & posicion, int NumeroPieza) const; 
        Pieza * ObtenerPrimero() const; 
        void Insertar(Pieza *); 
        Pieza * operator[](int) const; 
        int ObtenerCuenta() const { return suCuenta; }
        static ListaPiezas& ObtenerListaPiezasGlobal(){return ListaPiezasGlobal;}
};

ListaPiezas ListaPiezas::ListaPiezasGlobal;

ListaPiezas::ListaPiezas():
    apCabeza(0),
    suCuenta(0){}

ListaPiezas::~ListaPiezas(){
    delete apCabeza;
}

Pieza* ListaPiezas::ObtenerPrimero() const{
    if(apCabeza)
        return apCabeza->ObtenerPieza();
    else
        return NULL; // atrapar error aquí.
}

Pieza * ListaPiezas::operator[](int desplazamiento) const{
    NodoPieza * apNodo = apCabeza; 

    if(!apCabeza)
        return NULL;        // atrapar error aqui
    if (desplazamiento > suCuenta)
        return NULL;        // error
    for(int i = 0; i< desplazamiento; i++)
        apNodo = apNodo->ObtenerSiguiente();
    return apNodo->ObtenerPieza();
}

Pieza* ListaPiezas::Encontrar(int & posicion, int NumeroPieza) const{
    NodoPieza * apNodo = NULL; 

    for(apNodo = apCabeza, posicion = 0; 
        apNodo!= NULL;
        apNodo = apNodo->ObtenerSiguiente(), posicion++){
            if(apNodo->ObtenerPieza()->ObtenerNumeroPieza() == NumeroPieza)
                break;
        }
    if(apNodo == NULL)
        return NULL;
    else
        return apNodo->ObtenerPieza();
}

void ListaPiezas::Iterar(void (Pieza::*func)() const) const{
    if(!apCabeza)
        return;
    NodoPieza *apNodo = apCabeza; 
    do
    {
        (apNodo->ObtenerPieza()->*func)();
    } while (apNodo = apNodo->ObtenerSiguiente());    
}

void ListaPiezas::Insertar(Pieza * apPieza){
    NodoPieza * apNodo = new NodoPieza(apPieza); 
    NodoPieza * apActual = apCabeza;
    NodoPieza * apSiguiente = NULL; 
    int Nuevo = apPieza->ObtenerNumeroPieza(); 
    int Siguiente = 0;

    suCuenta++; 
    if(!apCabeza){
        apCabeza = apNodo; 
        return; 
    }

    // si este es más pequeño que el nodo cabeza
    // entonces se convierte en el nuevo nodo cabeza
    if(apCabeza->ObtenerPieza()->ObtenerNumeroPieza() > Nuevo){
        apNodo->AsignarSiguiente(apCabeza);
        apCabeza = apNodo;
        return;
    }


    for(;;){
        // si no hay siguiente, agregar éste
        if(!apActual->ObtenerSiguiente()){
            apActual->AsignarSiguiente(apNodo);
            return; 
        }

        // si va después de éste y antes del siguiente
        // entonces insertarlo aquí, de no ser así 
        // obtener el siguiente
        apSiguiente = apActual->ObtenerSiguiente();
        Siguiente = apSiguiente->ObtenerPieza()->ObtenerNumeroPieza(); 
        if(Siguiente > Nuevo){
            apActual->AsignarSiguiente(apNodo);
            apNodo->AsignarSiguiente(apSiguiente); 
            return;
        }
        apActual = apSiguiente;
    }
}

class CatalogoPiezas{
    private:
        ListaPiezas laListaPiezas;
    public:
        void Insertar(Pieza *); 
        int Existe(int NumeroPieza);
        Pieza * Obtener(int NumeroPieza);
        int operator+(const CatalogoPiezas &); // to be defin if this is int
        void MostrarTodo(){
            laListaPiezas.Iterar(&Pieza::Desplegar);}
};

void  CatalogoPiezas::Insertar(Pieza * nuevaPieza){
    int numeroPieza = nuevaPieza->ObtenerNumeroPieza();
    int desplazamiento;
    
    if(!laListaPiezas.Encontrar(desplazamiento, numeroPieza))
        laListaPiezas.Insertar(nuevaPieza);
    else{
        cout  << numeroPieza << " fue la "; 
        switch (desplazamiento){
            case 0: cout << "primera "; break;
            case 1: cout << "segunda "; break; 
            case 2: cout << "tercera "; break; 
            default: cout << desplazamiento+1 << "a "; 
        }
        cout << "entrada. ¡Rechazada!\n"; 
    }
}

int CatalogoPiezas::Existe(int NumeroPieza){
    int desplazamiento; 
    laListaPiezas.Encontrar(desplazamiento,NumeroPieza);
    return desplazamiento;
}

Pieza * CatalogoPiezas::Obtener(int NumeroPieza){
    int desplazamiento; 
    Pieza * laPieza = laListaPiezas.Encontrar(desplazamiento, NumeroPieza); 
    return laPieza;
}

int main(){
    CatalogoPiezas cp; 
    Pieza * apPieza = NULL; 
    int NumeroPieza; 
    int valor; 
    int opcion; 

    while(true){
        cout << "(0)Salir   |   (1)Auto   |   (2)Avion: "; 
        cin >> opcion;
        if(!opcion){
            break; 
        }
        cout << "¿Nuevo NumeroPieza?: "; 
        cin >> NumeroPieza; 
        if(opcion == 1){
            cout << "¿Anio del modelo? ";
            cin >> valor; 
            apPieza = new PiezaAuto(valor, NumeroPieza); 
        }
        else{
            cout << "¿Numero de motor?: "; 
            cin >> valor; 
            apPieza = new PiezaAeroPlano(valor, NumeroPieza); 
        }
        cp.Insertar(apPieza);
    }
    cp.MostrarTodo();
    return 0;
}