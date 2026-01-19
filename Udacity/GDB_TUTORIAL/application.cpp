#include <iostream>

using namespace std; 

void fun3(){
    int fun3variable = 25; 
    cout << fun3variable << endl; 
}

void fun2(){
    int fun2variable = 20; 
    cout << fun2variable << endl; 
    fun3();
}

void fun1(){
    int fun1variable = 15; 
    cout << fun1variable << endl; 
    fun2(); 
}

int main(){
    int mainVariable = 10; 
    cout << mainVariable << endl; 
    fun1(); 
    return 0;
}