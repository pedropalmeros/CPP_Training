#include <iostream>

using namespace std; 

class Mammal{
    public:
        // CONSTRUCTORS
        Mammal();
        ~Mammal();

        // ACCESS METHODS. 
        int getAge()const; 
        void setAge(int); 
        int getWeight()const; 
        void setWeight(int);
        void talk();
        void sleep();

    protected:
        int lAge;
        int lWeight;
};