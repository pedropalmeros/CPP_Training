#include <iostream> 
#include <fstream> 
#include <string> 

int main(){
    std::ifstream file("camera_values.txt"); 
    
    if(!file){
        std::cerr << "Error: Could not open file." << std::endl; 
    }

    // Camera class
    // Camera object
    std::string serialNumber, roll, pitch, yaw; 

    std::cout << "Serial Number | Roll | Pitch | Yaw" << std::endl; 

    // Read each line from the file and process it 
    while(file >> serialNumber >> roll >> pitch >> yaw){
        std::cout << serialNumber << " | " << roll << " | " << pitch << " | " << yaw << std::endl; 
    }
}