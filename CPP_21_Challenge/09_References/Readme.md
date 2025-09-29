# Referencias

## 1.- ¿Qué es una referencia? 

Una *referencia* es un alias o sinónimo; cuando crea una referencia, la inicializa con el nombre de otro objeto, que viene siendo el destino. A partir de ese momento, la <span style="color:red;">referencia actúa como un nombre alternativo para el destino</span>, y cualquier cosa que le haga a la referencia, en realidad se la hace al destino. 

``` c++
/************************************************************************************************************************************************
 * A reference is an alyas or synonim; when a reference is create ti has to be initialized with the name of other object of the same type
 * After initialization the referece works as an alternative name for the variable. and any thing that is done to the reference is done
 * to the original variable.
 ************************************************************************************************************************************************/

#include <iostream> 

using namespace std; 

int main(){
    int intOne; 
    int & ref2intOne = intOne; 

    intOne = 5; 
    cout << "intOne: " << intOne << endl;
    cout << "ref2: " << ref2intOne << endl; 

    ref2intOne = 7; 

    cout << "intOne: " << intOne << endl;
    cout << "ref2: " << ref2intOne << endl;

}
```

## 2.- Uso del operaddor de dirección (&) en referencias. 

Si pide la dirección de una referencia, ésta regresa la dirección de su destino. Ésa es la naturalea de las referencias: <span style="color:red;">Son un alias para el destino</span>. Las referencias se incializan al crearse, y siempre actúan como sinónimo para su destino, incluso al aplicar el operador de dirección. 

Las referencias no se pueden reasignar y son siempre un alias para su destino. 

``` c++
/***************************************************************************************************************
 * If the address of a reference is obtained and compared with the address of the original variable, 
 * It can be observed that both address are the same, this is the nature and the purpose of the reference
 **************************************************************************************************************/

#include <iostream>

using namespace std; 

int main(){
    int intOne; 
    int & oneRef = intOne; 

    intOne = 5; 
    cout << "intOne: " << intOne << endl; 
    cout << "oneRef: "  << oneRef << endl; 

    cout << "&intOne: "  << &intOne << endl; 
    cout << "&oneRef: "  << &oneRef << endl;

    return 0;
    
}

```
Cualquier objeto se puede referencia, incluyendo los objetos definidos por el usuario. 
``` c++
GATO pelusa; 
GATO & rGatoRef = pelusa;
```

<span style="color:red;">Una referencia ese declara escribiendo el tipo, seguido del operador de referencia (`&`) y del nombre de la referncia. Las referencias se deben inicializar al momento de su creación.</span>



## 3.- Paso de arguments de funciones por referencia. 

Las funciones tienen dos limitaciones : los argumentos se pasan por valor y la instrucción `return` sólo puede regresar un valor. 

Si se psan valores a una funció por referencia se pueden resolver ambas limitaciones . En `C++`, pasar por referencia se logra de dos formas: usando apuntadores y usando referencias. Observer la diferencia: <span style="color:orange;">Se pasa por referencia usando un apuntador, ose pasa por referencia usando una refencia.</span>

La sintaxis para usar un apuntador es distitna de la requerida para pasar una referencia. pero el efecto neto es el mismo. En lugar de que se cree una copia dentro del alcance de la función, en realidad se pasae el objeto original a la función ( en realidad se pasa la dirección del objeto, es decir, su referencia). 

Si se pasa un objeto por referencia, se permite que la función cambie el objeto al que hace referencia. 

---
#### Ejemplo de código pasando por referencia utilizando referencias
``` c++
#include <iostream> 

using namespace std;

void change(int &x, int &y);

int main(){
    int x = 5, y = 10;

    cout << " main(). Before changing variables, x: " << x << " y: "  << y << endl << endl; 
    
    change(x,y); 

    cout << " main(). After changing variables, x: " << x << " y: "  << y << endl << endl; 

}


void change(int &x, int &y){
    int temp;

    cout << "Change(). Before changing variables, x: " << x << " y: " << y<< endl;  

    temp = x; 
    x = y;
    y = temp; 

    cout << "Change(). After changing variables, x: "  << x << " y: " << y << endl << endl;  
}
```
---
#### Ejemplo de código pasando por referencia utiliando punteros. 
``` c++
#include <iostream> 

using namespace std;

void change(int *x, int *y);

int main(){
    int x = 5, y = 10;

    cout << " main(). Before changing variables, x: " << x << " y: "  << y << endl << endl; 
    
    change(&x,&y); 

    cout << " main(). After changing variables, x: " << x << " y: "  << y << endl << endl; 

}


void change(int *x, int *y){
    int temp;

    cout << "Change(). Before changing variables, x: " << *x << " y: " << *y<< endl;  

    temp = *x; 
    *x = *y;
    *y = temp; 

    cout << "Change(). After changing variables, x: "  << *x << " y: " << *y << endl << endl;  
}
```


## 4.- Paso de `enum` en funciones

``` c++
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
```


## 5.- Cómo pasar parámetros por referencia  para tener eficacia. 

Cada vez que le pasa un objeto por valor a una función, se crea una copia del objeto. Cada vez que regresa un objeto por valor de una funciónn, se crea otra copia. 

ON objetos más grandes creados por el usuario, el costo es mayor. El tamaño de un objeto creado por el usuario en la pila es la suma de cada una sde sus vriables miembro. Éstas, a su vez, pueden ser objetos creados por el usuario, y pasar toda esa estructura masiva copiándola en la pila puede provocar una reducción bastante considerable en el rendimiento y consumo exesivo de memoria. 

Cada una de estas copias temporales se crea cuando el compilador llama a un constructor: el constructor de copia. 

El constructor de copia se llama cada vez que se coloca en la pila una copia temporal del objeto. 

Con objetos grandes, estas lamadas al constructor y al destructor pueden disminuir la velocidad y aumentar el uso de la memoria. 


``` c++
#include <iostream>

using namespace std; 

class SimpleCat{
    public: 
        SimpleCat();
        SimpleCat(SimpleCat &); // Copy constructor
        ~SimpleCat();
}; 

SimpleCat::SimpleCat(){
    cout << "CONSTRUCTOR SimpleCat"<< endl; 
}

SimpleCat::SimpleCat(SimpleCat &){
    cout << "COPY CONSTRUCTOR SimpleCat" << endl; 
}

SimpleCat::~SimpleCat(){
    cout << "DESTRUCTOR SimpleCat" << endl; 
}


SimpleCat FunctionOne(SimpleCat daCat);
SimpleCat * FunctionTwo(SimpleCat *daCat); 

int main(){
    cout << "Create a cat ..." << endl; 
    SimpleCat Pelusa; 
    cout << "Calling to FunctionOne ... "  << endl; 
    FunctionOne(Pelusa);
    cout << "Calling to FunctionTwo..."  << endl; 
    FunctionTwo(&Pelusa);
    return 0;
}

//FunctionOne
SimpleCat FunctionOne(SimpleCat daCat){
    cout << "FunctionOne. Going back..."  << endl; 
    return daCat;
}

//FunctionTwo
SimpleCat*  FunctionTwo(SimpleCat *daCat){
    cout << "Function Two, Comming back ... "  << endl; 
    return daCat;
}
```

## 6.- Paso de un apuntador `const`

Pasar por fvloar es como dar a un musueo una fotografía de su obra maestra en lugar de darle la verdadera. Si los vándalos la rayan, no se daña la original. Pasar po referencia es como enviar su dirección particular al museo y hacer que vengan invitados y  ven la obra verdadera. 

La solución es pasar un apuntador constante a un objeto. Hacer esto evita que se llame a cualquiere meétodo que no sea constante en el objeto. 

``` c++
#include <iostream> 

using namespace std; 

class SimpleCat{
    public:
        SimpleCat();
        SimpleCat(SimpleCat &);
        ~SimpleCat();
        int getAge() const; 
        void setAge(int age);
    private:
        int lAge;
};

SimpleCat::SimpleCat(){
    cout << "GENERIC CONSTRUCTOR of SIMPLECAT";
    this->lAge = 1; 
}


SimpleCat::~SimpleCat(){
    cout  << "DSESCTRUCTOR of SimpleCat" << endl;
}

void SimpleCat::setAge(int age){
    this->lAge = age;
}

int SimpleCat::getAge() const{
    return this->lAge;
}


const SimpleCat * const FunctionTwo(const SimpleCat  * const daCat);

int main(){
    cout << "Create a cat..." << endl; 
    SimpleCat Pelusa;
    cout << "Pelusa is "  << Pelusa.getAge() << " years old." <<  endl; 

    int age = 5; 

    Pelusa.setAge(age);

    cout << "Pelusa is "  << Pelusa.getAge() << " years old." << endl; 
    cout << "Calling to FunctionTwo ... " << endl; 
    
    FunctionTwo(&Pelusa);
    cout << "Pelusa is " << Pelusa.getAge() << " years old." << endl; 

    return 0;
}

// FunctionTwo pass a const pointer
// This function returns a constant pointer to a constant object
const SimpleCat * const FunctionTwo(const SimpleCat * const theCat){
    cout << "Function Two ... Going back ... " <<endl; 
    cout << "Pelusa is " << theCat->getAge() << " years old." << endl; 
    //theCat->setAge(8); // If this line in uncommented it will break since it is a constant pointer,
                         // In this case the theCat cannot be change neither the pointer can change.
    cout << "EXITING Function Two" << endl; 
    return theCat;  
}

```


```python

```


```python

```
