// SN, roll, pitch, yaw
// 001, -1.8956, 31.4567, -0.7419

#include <iostream>
#include <string> 
#include <sstream> 

using namespace std; 

int main(){

    string line = "001, -1.8956, 31.4567, -0.7419"; 

    size_t first_comma = line.find(','); 
    size_t second_comma = line.find(',',first_comma+1); 
    size_t third_comma = line.find(',',second_comma+1); 

    string serialNumber = line.substr(0, first_comma); 
    string roll = line.substr(first_comma+1, second_comma - first_comma -1 ); 
    string pitch = line.substr(second_comma + 1, third_comma - second_comma - 1); 
    string yaw = line.substr(third_comma + 1); 

}