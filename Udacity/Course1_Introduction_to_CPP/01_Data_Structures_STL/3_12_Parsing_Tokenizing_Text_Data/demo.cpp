#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std; 

void example_01(string location_info){
    size_t locationSize = sizeof(location_info)/ sizeof(location_info[0]); 

    for(int i = 0; i < locationSize; i++){
        cout << location_info[i] << " is at index: " << i << endl; 
    }

}

void example_02(string location_info){
    std::size_t first_pipe = location_info.find("|");
    std::cout << first_pipe << endl;

    std::size_t second_pipe = location_info.find("|", first_pipe+1);
    std::cout << second_pipe << std::endl; 
}


void example_03(string location_info){
    std::stringstream ss(location_info); 
    std:;string lat, lon, city, state; 

    std::getline(ss, lat, '|'); 
    std::getline(ss, lon, '|'); 
    std::getline(ss, city, '|');
    std::getline(ss, state); 

    std::cout << lat << "  " << lon << "  " << city << "  " << state << std::endl;
}

int main(){
    string location_info = "11.1111 | 22.2222 | City | Sate"; 

    example_01(location_info); 


    example_02(location_info);

    example_03(location_info);

    return 0; 
}