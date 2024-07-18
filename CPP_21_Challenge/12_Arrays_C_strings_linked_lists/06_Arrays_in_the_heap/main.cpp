/************************************************************************************************************************
 * 
 */


#include <iostream> 

using namespace std; 

class Cat{
    private:
        int lWeight;
        int lAge;
    public:
        Cat():lWeight(5),lAge(1){}
        ~Cat(){cout << "Calling destructor" << endl; }
        int getAge() const{ return this->lAge;}
        void setAge(int aAge){lAge = aAge;}
        int getWeight()const{return this->lWeight;}
        void setWeight(int aWeight){lWeight = aWeight;}
};

int main(){
    Cat * Family = new Cat[500]; 
    int i ; 

    for( i =0 ; i < 500; i++){
        Family[i].setAge(2*i+1); 
    }
    for( i=0; i < 500; i++){
        cout << "Cat " << i+1 << ": " << Family[i].getAge() << ". " << endl; 
 
    }

    delete [] Family; 
    return 0;
}
