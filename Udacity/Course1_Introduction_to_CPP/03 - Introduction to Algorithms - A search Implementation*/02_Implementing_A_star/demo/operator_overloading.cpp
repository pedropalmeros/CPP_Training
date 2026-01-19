#include <iostream> 

class Add{
    public: 
        int operator()(int a, int b) const{
            return a + b;
        }
}; 

int main(){
    Add add; 
    int result = add(3,4); 
    std::cout << result << std::endl;
}