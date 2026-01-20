#include <iostream> 
#include "utils.h"

int main(){
    std::cout << "======= main.cpp =======" << std::endl; 

    // External Linkage
    incrementExternal(); 
    incrementExternal(); 

    std::cout << "[main] externalCounter = " << externalCounter << "\n\n"; 

    // Direct access to interl symbols
    // NOTE: IF THE NEXT LINE IS UNCOMMENT THERE WILL BE AN ISSUE SINCE NEITHER THE FUNCIONS NOR THE VARIABLES ARE VISIBLE
    // incrementInternal(); 
    // incrementAnon(); 
    // std::cout << internalCounter; 
    // std::cout << anonCounter; 

    int internalCounter = 3; 
    std::cout << "[main] internalCounter = " << internalCounter << "\n\n"; 

    incrementInternalVariables(); 

    return 0;
}