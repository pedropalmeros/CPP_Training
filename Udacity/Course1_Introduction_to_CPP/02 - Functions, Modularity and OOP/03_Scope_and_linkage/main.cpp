#include <iostream> 
#include "utils.h"

int main(){
    std::cout << "======= main.cpp =======" << std::endl; 

    // External Linkage
    incrementExternal(); 
    incrementExternal(); 

    std::cout << "[main] externalCounter = " << externalCounter << "\n\n"; 

    // Direct access to interl symbols
    // incrementInternal(); 
    // incrementAnon(); 
    // std::cout << internalCounter; 
    // std::cout << anonCounter; 

    int internalCounter = 3; 
    std::cout << "[main] internalCounter = " << internalCounter << "\n\n"; 

    incrementIntervalVariables(); 

    return 0;
}