#include <iostream>
#include <string>

using namespace std; 

//The base class
class Student{
    private:
        int id; 
    public:
        void setId(int idIn);
        int getId()const;
        Student();
};

Student::Student(){
    id = 0000000000;
}

void Student::setId(int idIn){
    id = idIn; 
}

int Student::getId()const{
    return id; 
}

class GradStudent : public Student{
    private:
        string degree;
    public:
        GradStudent();
        void setDegree(string degreeIn);
        string getDegree();
};

GradStudent::GradStudent(){
    degree = "undeclared" ;
}

void GradStudent::setDegree(string degreeIn){
    degree = degreeIn;
}

string GradStudent::getDegree(){
    return degree;
}