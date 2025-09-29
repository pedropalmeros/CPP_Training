# Day 8 

## 1.- Pila y el heap

Las variables locales se encuentran en la pila. 

El heap es una secci'on masive de memeoria en la que miles de casillas enueradas en forma secuencial permanece en espera de sus datos. Lo malo es que no puede etiquetar estas casillas, como se puede ahcer con la pila. Tiene que pedir la dirección de la casilla que va a reservar y luego guardar esta dirección en un apuntador. Usted no sabe done está el apuntador, pero sabe cómo llegar a él, accede utiliando la dirección. No tiene que conocer ese número, sólo tiene que colocarlo en un apuntador. El apuntador  le da acceso a sus datoss sin molestarlo con los detalles. 

la pila se limpia automáticamente cuando una fucnión termina. Todas las variables locales les quedan fuera de alcance, y se eliminan de la pila. El heap se limpia hasta que termina el programa, y es responsabilidad de usted liberar cualquier memoria que haya reservado, cuando ya no la utilice. 

La ventaja de usar el `heap` es que la memoria que suted reserve estará disponible hasta que la libere explícitamente. 

### `new`

En C++ se utiliza la palabra reservada `new` para asignar memoria en el heap. Después de `new` debe ir el timpo de objeto que quiere asignar, para que el compilador sepa cuána memoria se requiere. 

``` c++_
unsigned shor int * apApuntador; 
apApuntador = new unsigned short int; 
```



### `delete`
Al terminar de utilizar su área de memoria, debe llamar a `delete` para que actúe sobre el apuntador. `delete` libera la memoria reservada. La memoria asignada con `new` no se libera automaticamente

```c++
delete apApuntador; 
```

Al eliminar el pauntador, lo que realmente está haciendo es liberar la memroia cuya dirección está guardada en el apuntador. 


``` c++
/***************************************************************************************************
 * NEW - this word is used to assign mememory in the heap. After the 'new' follows the object type
 * to be assigned, so the compiler can figure out the size of memory to be assigned. 
 * 
 * DELETE - after using the memory, the 'delete' has to be used to release and clean the memory. 
 ***************************************************************************************************/
#include <iostream> 

using namespace std;

int main(){
    int localVar = 5; 
    int * apLocal = &localVar; 
    int * apHeap = new int; 

    *apHeap = 7; 
    cout << "localVar: " << localVar << endl;
    cout << "*apLocal: " << *apLocal << endl; 
    cout << "*apHeap: "  << *apHeap << endl; 

    delete apHeap;

    apHeap = new int; 
    *apHeap = 9; 
    cout << "*apHeap: " << *apHeap << endl; 
    delete apHeap; 

    return 0; 


}
```



## 2.- Creación y eliminación  de hobjetos en heap 

Así como se puede crear un apuntador a un entero, también puede crear un apuntador a cualquier objeto. 

```
Gato *apGato = new Gato;
```

Cuando llama a `delete` para que actúe sobre un apuntador a un objero en el `heap`, el destructor de ese objeto se llama antes de que se libere la memoria. Esto le da a su clase una oportunida para limpiarse. 


``` c++
#include <iostream> 

using namespace std; 

class SimpleCat{
    private:
        int itsAge;

    public: 
        SimpleCat();
        ~SimpleCat();
};

SimpleCat::SimpleCat(){
    cout << "Cat constructor has been called" << endl; 
    itsAge = 1; 
}

SimpleCat::~SimpleCat(){
    cout << "Destructor has been called"  << endl; 
}

int main(){
    cout << "SimpleCat pelusa ..... "  << endl; 
    SimpleCat Pelusa; 
    cout << "Creating SimpleCat in the heap" << endl; 
    SimpleCat *Felix = new SimpleCat;
    cout << "delete Felix" << endl; 
    delete Felix; 
    cout << "Exiting the program Pelusa automanage its memory" << endl; 
}
```







## 3.- Acceso a los datos miembro


Usted tiene acceso a los datos miembro ya las funciones mediante el operador de punto (`.`) para los objetos creados de forma local. Para tener acceso al objeto  en el heap, debe de desreferenciar el apuntador y llamar al operador de punto en el objeto alq ue apunta el apuntador. Por ejemplo 

``` c++
(*apFelix).ObtenerEdad();
```

Los paréntesis se utilizan pra asegurar que `apFelix` sea desreferenciado antes de tener acceso a `ObtenerEdad()`.

Como esto es un poco extraño. C++ proporcioona un operador de método abreviado para el acceso indirecto: el operador de flecha (`->`). 


``` c++
/**********************************************************************************************************
 * To access to the data members and functions from an object the '.' can be used.
 * If an object is in the heap, first it has to be deferecenced, and then the point and the attribute or method. 
 * Ex.
 * (*apFelix).getAge();
 * This is kind of strange, hence c++ uses the arrow operator 
 * (*apFelix).getAge()   EQUALS  apFelix->getAge()
 ************************************************************************************************************/

#include <iostream> 

using namespace std; 

class SimpleCat{
    private:
        int age;
    public:
        SimpleCat();
        ~SimpleCat(){}
        int getAge();
        void putAge(int inAge);
};

SimpleCat::SimpleCat(){
    age = 2;     
}

int SimpleCat::getAge(){
    return age;
}

void SimpleCat::putAge(int inAge){
    age = inAge;
}

int main(){
    SimpleCat *Pelusa = new SimpleCat; 
    cout << "Pelusa is: " << Pelusa->getAge() << " years old." << endl;
    Pelusa->putAge(5);
    cout << "Pelusa is: " << (*Pelusa).getAge() << " years old." << endl;
    (*Pelusa).putAge(8); 
    cout << "Pelusa is: " << Pelusa->getAge() << " years old." << endl; 

    return 0; 
}

```

## 4.- Datos miembro en el heap

Uno o más datos de una clase pueden ser apuntadores  a un objeto que se encuentre en el heap

``` c++
/*************************************************************************************************
 * Many data members of a class can be located at the heap.
 * Many attributes of the class can be pointing to objects that live in the heap. 
 ************************************************************************************************/

#include <iostream> 

using namespace std; 

class SimpleCat{
    private:
        int *age;       // This is a pointer, the object can be at the heap
        int *weight;    // This is a pointer, the object can be at the heap

    public: 
        SimpleCat();
        ~SimpleCat();

        int getAge();
        void putAge(int); 

        int getWeight(); 
        void putWeight(int);
};

SimpleCat::SimpleCat(){
    /* Since age and weight are pointers a good practice is to initialize them in the constructor*/
    age = new int(2);
    weight = new int(5);
}

SimpleCat::~SimpleCat(){
    /* Since the age and weight live in the heap they should be deleted in the destructor to release memory*/
    delete age; 
    delete weight;
}

int SimpleCat::getAge(){
    return *age;
}

void SimpleCat::putAge(int inAge){
    *age = inAge;
}

int SimpleCat::getWeight(){
    return *weight;
}

void SimpleCat::putWeight(int inWeight){
    *weight = inWeight;
}

int main(){
    SimpleCat *Pelusa = new SimpleCat; 

    cout << "Pelusa is "  << Pelusa->getAge() << " years old."  << endl; 
    Pelusa->putAge(9); 
    cout << "Pelusa is "  << Pelusa->getAge() << " years old."  << endl; 

}
```

## 5.- El apuntador `this`

Toda función miembro de una clase tiene un parámetro oculto: El apuntador `this`. El apuntador `this` apunta al propio objeto. Por lo tanto, en cada llamada a `ObtenerEdad()` o a `AsignarEdad()`, el apuntador `this` para el objeto se incluye como un parámetro oculto. 


---
main program 
``` c++
/*************************************************************************************************
 * A class in C++ has a very special pointer "this". The pointer is pointing to the same class. 
 * For me it helps me in the set/get functions to avoid confussions and to be concient that the 
 * attribute or method belongs to the class.
 ************************************************************************************************/

#include <iostream> 
#include "rectangle.hpp"

using namespace std; 

int main(){
    Rectangle Rect;
    cout << "The rectangle is " << Rect.getWidth() << " feets on its width." << endl; 
    cout << "The rectangle is " << Rect.getHeight() << " feets on its height."  << endl; 
    Rect.putWidth(10);
    Rect.putHeight(15);
    cout << "The rectangle is " << Rect.getWidth() << " feets on its width." << endl; 
    cout << "The rectangle is " << Rect.getHeight() << " feets on its height."  << endl; 

    return 0; 
}
```
---
library `rectangle.hpp`
In this file the `this` pointer is being used. 

``` c++
#include <iostream> 

using namespace std; 

class Rectangle{
    private:
        int lWidth; 
        int lHeight; 

    public: 
        Rectangle();
        ~Rectangle(); 

        void putHeight(int); 
        int getHeight();

        void putWidth(int);
        int getWidth();
};

Rectangle::Rectangle(){
    this->lWidth = 10; 
    this->lHeight = 5; 
}

Rectangle::~Rectangle(){}

void Rectangle::putHeight(int height){
    this->lHeight = height;
}

int Rectangle::getHeight(){
    return this->lHeight;
}
``` 

## 6.- Apuntadores const

En los apuntadores, se pueede utilizar la palabra reservada `const` antes del tipo , después del tipo, o en ambos lugares. 

`const int*  apUno; // No se pede cambiar el entero, si el spuntador. `

`int * const apDos; // No se puede cambiar el apuntador, pero si el entero. `

`const int * const apTres; // No puede cambiar ni el apuntador ni el entero. `


`apUno` es un apuntador a un valor entero constante. El valor al que apunta no se puede cambiar. 

`apDos` es un apuntador constante a un entero Se puede cambiar el entero, pero `apDos` no puede apuntar a ninguna otra cosa. 

`apTres` es un apuntador constante a un entero constante. El valor al que apunta no se puede cambiar, y `apTres` no puede apuntar a ninguna otra cosa. 

El truco para usar esto sin problemas es mirar a la derecha de la palabra reservada `const`para saber qué se está declarando como constantee. 

``` c++
/********************************************************************************************************
 * You can use the reserved word const in the pointers, in before and after the type and in both places. 
 * Example
 * const int* pointer1;         || The int value  cannot be changed.
 * int* const pointer2;         || The value can be changed but not the pointer   
 * const int* const pointer3;   || The value cannot be changed, the pointer cannot be changed.
 * "pointer1" is pointing to a constant value, hence the value at which it is pointing cannot be changed. 
 * "pointer2" is a constant pointer. The value of the integer can change but pointer2 cannot point other address
 * "pointer3" is a constant pointer to a constant value, neither both of them can be changed. 
 * 
 */

#include "main.hpp" 

int main(){

    // This pointer can change the value of the Rectangle and can point to other objects if it is required.
    Rectangle * apRect = new Rectangle; 

    // The value of the Rectangle cannot be changed. 
    const Rectangle * apConstRect = new Rectangle();

    // The value of the Rectangle can be changed but no the address of the pointer
    Rectangle * const apConstPointer = new Rectangle();

    cout << "apRect width: " << apRect->getWidth() << " ft. "  << endl; 
    cout << "apConstRect width: " << apConstRect->getWidth() << " ft." << endl; 
    cout << "apConstPointer: "  << apConstPointer->getWidth() << " ft." << endl; 

    apRect->setWidth(20); 
    // apConstRect->setWidth(20); ERROR IF UNCOMMENT. since the rectangle cannot be changed. 
    apConstPointer->setWidth(20);


    cout << "apRect width: " << apRect->getWidth() << " ft. "  << endl; 
    cout << "apConstRect width: " << apConstRect->getWidth() << " ft." << endl; 
    cout << "apConstPointer: "  << apConstPointer->getWidth() << " ft." << endl; 
}

```


```python

```
