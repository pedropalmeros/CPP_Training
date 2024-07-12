/*********************************************************************************************************************************************************
 * In C++, we can create generic lcasses as well as functions. We use the same template type placeholder as we did for functions. 
 * Let's look at an example of a generic lass.
 ********************************************************************************************************************************************************/
#include <iostream> 

using namespace std; 

template <class T>
class StudentRecord{
    private:
        const int size = 5; 
        T grade; 
        int studentId; 
    public:
        StudentRecord(T input); 
        void setId(int idIn); 
        void printGrades();
};

template<class T>
StudentRecord<T>::StudentRecord(T input){
    grade = input;
}

template<class T>
void StudentRecord<T>::setId(int idIn){
    studentId = idIn; 
}

template<class T>
void StudentRecord<T>::printGrades(){
    cout << "ID#: " << studentId << ": " ; 
    cout << grade << endl; 
    cout << endl; 
}

int main(){
    // StudentRecord is the generic lass
    // The constructor sets the grade value
    StudentRecord<int> srInt(3); 
    srInt.setId(111111111);
    srInt.printGrades(); 

    StudentRecord<char> srChar('B');
    srChar.setId(2222222);
    srChar.printGrades(); 

    StudentRecord<float> srFloat(3.333333); 
    srFloat.setId(3333); 
    srFloat.printGrades(); 

    StudentRecord<string> srString("B-");
    srString.setId(4444); 
    srString.printGrades();

    return 0; 


} 