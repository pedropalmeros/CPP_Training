/***************************************************************************************************************************
 * The copy constructor is called everytime a copy of an object is done.
 * ALL THE COPY CONSTRUCTORS TAKE a reference to an object of the same class. It is a good idea that set the reference as 
 * constant to avoid changes during the copying process. 
 * 
 * The default copy constructor just cpies every member variable of the referenced objet as parametes to the variables of 
 * the new objcet. This is known as DATA MEMBER COPY. 
 ***************************************************************************************************************************
 * IN THE NEXT PROGRAM A USER COPY CONSTRUCTOR IS GOING TO BE CODED
 ***************************************************************************************************************************/

#include <iostream> 

using namespace std;

class Cat{
    private:
        int *lAge; 
        int *lWeight; 
    public:
        Cat(); 
        Cat(const Cat &);
        ~Cat(); 
        int getWeight() const;
        void setWeight(int aWeight);
        int getAge() const; 
        void setAge(int aAge); 
};

Cat::Cat(){
    lAge = new int(2);
    lWeight = new int(3); 
}

Cat::Cat(const Cat &rhs){
    cout << "COPY CONSTRUCTOR";
    lAge = new int(rhs.getAge());
    lWeight = new int(rhs.getWeight());
}

Cat::~Cat(){
    delete lAge; 
    delete lWeight; 
    lAge = NULL;
    lWeight = NULL;
}

int Cat::getWeight() const{
    return *lWeight;
}

void Cat::setWeight(int aWeight){
    *lWeight = aWeight;
}

int Cat::getAge() const{
    return *lAge;
}

void Cat::setAge(int aWeight){
    *lAge = aWeight;
}

int main(){
    Cat Pelusa; 
    cout << "Pelus is: "  << Pelusa.getAge() << " years old. " << endl; 
    cout << "Setting Pelusa's age to 6" << endl; 
    Pelusa.setAge(6); 
    cout << "Creating Silvestre from pelusa" << endl; 
    Cat Silvestre(Pelusa);
    cout << "Pelusa's age: " << Pelusa.getAge() << " years." << endl;
    cout << "Silvestre's age: " << Silvestre.getAge() << " years." << endl; 
    cout << "Setting Peslusa's age to 10" << endl; 
    Pelusa.setAge(10); 
    Silvestre.setAge(15); 
    cout << "Pelusa's age: " << Pelusa.getAge() << " years." << endl;
    cout << "Silvestre's age: " << Silvestre.getAge() << " years." << endl; 
    return 0;
}