#include <iostream> 
#include <string> 

using namespace std; 

int main(){
    string city = "San Francisco"; 
    size_t firstAn = city.find("an"); // return 1 because is the firs incidence
    size_t secondAn = city.find("an",firstAn+1); // returns 6; 


    size_t pos = city.find("Chicago"); 
    if (pos == string::npos){
        cout << "City not found." << endl; 
    }

    size_t thridAn = city.find("an", 14 ); // returns string::npos/ 

    string x = city.substr(13); //returns empty string; 
    x = city.substr(13,3);  // returns empty string; 
    // string y = city.substr(100,5); // if it is uncommented it will trow an errror


    cout << endl; 
    return 0;
    
}