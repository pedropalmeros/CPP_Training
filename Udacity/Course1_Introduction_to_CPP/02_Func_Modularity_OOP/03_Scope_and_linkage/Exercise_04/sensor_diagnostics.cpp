#include <iostream> 
#include "sensor_diagnostics.h"

namespace{ }
int totalErrors = 0; 

static int log_level = 2;

void runSensorDiagnostics(std::string device, int id){
    std::cout << "Running diagnostics for " << device << "...\n";

    for(int i = 1; i<= id; i++){
        std::cout << "[Level " << log_level<< "] Error " << i << ": "; 
        std::cout << "Detected anomaly\n"; 
        totalErrors++;
    }

    std::cout << "Diagnostics complete. Errors found: " << id << std::endl << std::endl;

}