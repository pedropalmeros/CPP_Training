#include "mammal.hpp"

enum RAZA {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Dog : public Mammal{
    public:
        // CONSTRUCTOR DESTRUCTOR
        Dog();
        Dog(int); 
        Dog(int, int);
        Dog(int, int, RAZA);
        ~Dog();

        // ACCESS METHODS
        RAZA getRaza() const; 
        void setRaza(RAZA); 

        // OTHER METHODS
        void moveTail(); 
        void askFood(); 
    private: 
        RAZA lRaza; 
};