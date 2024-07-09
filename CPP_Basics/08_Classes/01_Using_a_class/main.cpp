/* Goal: Practice using a class*/

#include <iostream>
#include <string>

using namespace std; 

class Student{
    string name; 
    int id; 
    int gradDate;

    public: 
        void setName(string nameIn);
        void setId(int idIn); 
        void setGradDate(int dateIn);
        string getName();
        int getId();
        int getGradDate();
        void print();
};

void Student::setName(string nameIn){
    name = nameIn; 
}

void Student::setId(int idIn){
    id = idIn; 
}

void Student::setGradDate(int gradDateIn){
    gradDate = gradDateIn;
}

void Student::print(){
    cout << name << " " << id << " " << gradDate; 
}

string Student::getName(){
    return name; 
}

int Student::getId(){
    return id; 
}

int Student::getGradDate(){
    return gradDate;
}

int main(){
    int integer1; 
    float float1;
    Student student1; 

    integer1 = 4; 
    float1 = 4.333; 

    student1.setName("Catherine Gamboa"); 
    student1.setId(54345);
    student1.setGradDate(2017);

    // Let's print the values of our variables
    cout << "integer1 = " << integer1 << endl; 
    cout << "float1 = "  << float1 << endl; 
    
    // There are two ways we can print the values of our class:
    // the frist is to call the print function we created.
    cout << "Using the Student::print function" << endl; 
    cout << "Student1 = " ; 
    student1.print();
    cout << endl << endl; 

    // The second is to access each member of the class using the get functions
    cout << "Using the student access functions. " << endl; 
    cout << "Student1 name = " << student1.getName() << endl; 
    cout << "Student1 ID = "  << student1.getId() << endl; 
    cout << "Student Grad Date = " << student1.getGradDate() << endl; 

    return 0; 
}