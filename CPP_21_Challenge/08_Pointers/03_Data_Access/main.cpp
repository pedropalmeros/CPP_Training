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
