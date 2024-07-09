/* This program accepts inputs from the input.txt file*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int year = 0;
    int age = 0;
    string name = "";

    cout << "What year is your favorite?: ";

    // get the user response and assign it to the variable year
    cin >> year; 

    //output response to user
    cout << "How interesting, your favorite year is " << year << endl; 

    // print a message to the user
    cout << "At what age did you lear to ride a bike? ";
    
    // get the user response and assign it to the variable age
    cin >> age;

    cout << "How interesting you learned to ride at " << age << endl; 

    cout << "What is your name? "; 
    cin >> name; 
    cout << "Hello " << name << endl; 
    return 0 ;

}