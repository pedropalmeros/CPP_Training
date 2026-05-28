#include <iostream> 
#include <string> 

class Employee{
    private: 
        std::string company; 
        std::string given; 
        std::string surname; 

    public: 
        Employee();             // default: sets company
        Employee(std::string g, std::string s); // delegates to default, then sets name
        void print() const; 
}; 

Employee::Employee():company("Acme Inc."){}

Employee::Employee(std::string g, std::string s):Employee(){
    this->given = g; 
    this->surname = s;
}

void Employee::print() const {
    std::cout << "Company: Acme Inc. - Name: "; 
    given.empty()?std::cout<<" ":std::cout<<this->given<<" ";
    surname.empty()? std::cout<<" " : std::cout<<this->surname;
    std::cout << std::endl;
}

int main(){
    Employee e1;
    e1.print(); 

    Employee e2("Ada","Lovelance"); 
    e2.print(); 
}