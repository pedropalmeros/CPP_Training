/**************************************************************
 * GOAL: Practice creating and using a class
 * Use the class 'Dog' to create to
 * instances of the class, dog1 and dog2.
 * Assign dog1 the name: Trixie
 * Assign dog2 the name: Kali
 * Assign dog 1 the licence #1234
 * Assign dog 2 the licence #5678
 * Print the information of each dog. 
 **************************************************************/

#include "main.hpp" 

int main(){
    Dog dog1, dog2; 

    dog1.setName("Trixie");
    dog1.setLicence(1234);

    dog1.describe();
    
    dog2.setName("Kali");
    dog2.setLicence(5678);
    dog2.describe();
    return 0; 
}