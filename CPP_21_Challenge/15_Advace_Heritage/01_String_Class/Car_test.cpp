#include <iostream> 
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>    // Hoa actual
#include <thread>   // Pausas temporales
#include <chrono>   // Manejo de tiempo
#include <iomanip> // Dar fortmato al texto

using namespace std;

struct Sensor{
    string name; 
    int value; 
    int minValue; 
    int maxValue; 
    int warningThreshold; 
    string alertMessage;
    string status;
};

// Generar aleatorios
int generateValues(int min, int max){
    return min + rand() % (max - min +1 );
}

int main(){
    srand(time(0)); 

    vector<Sensor> sensors = {{
        "Speed", 
        0, 
        0,
        180,
        140,
        "HIGH SPEED",
        "OK",
    },
    // BATERIA
    {
        "Battery",
        100, 
        0, 
        100,
        20,
        "LOW BATTERY",
        "OK"
    },
    // TEMPERATURA
    {
        "Engine Temp", 
        70, 
        60, 
        120,
        95,
        "HIGH TEMPERATURE", 
        "OK"
    },
    // Presion de frenos
    {
        "Break Pressure", 
        30, 
        20,
        50,
        25,
        "LOW PRESSURE", 
        "OK",
    }
};
    while(true){
        // Genera nueva velocidad
        sensors[0].value = generateValues(sensors[0].minValue, sensors[0].maxValue);

        // Bateria
        if(sensors[1].value > 0 ){
            sensors[1].value -= rand() %2; 
        }

        // Temperatura
        sensors[2].value = generateValues(sensors[2].minValue, sensors[2].maxValue);

        // Sensor Frenos
        sensors[3].value = generateValues(sensors[3].minValue, sensors[3].maxValue);

        // VALIDACIONES
        for(auto& sensor : sensors ){
            if(sensor.name == "Battery"){
                sensor.status = (sensor.value < sensor.warningThreshold) ? sensor.alertMessage : "OK"; 
            }else{
                sensor.status = (sensor.value > sensor.warningThreshold) ? sensor.alertMessage : "OK";
            }
        }

        system("clear"); 

        // ENCABEZADO
        cout << "====================================================" << endl; 
        cout << "           VEHICLE SENSOR MONITOR                              " << endl; 
        cout << "====================================================" << endl; 

        cout << left
            << setw(20) << "Sensor"
            << setw(15) << "Value"
            << setw(20) << "Status"
            << endl; 
        cout << "----------------------------------------------------" << endl; 

        for (const auto& sensor : sensors){
            cout << left
            << setw(20) << sensor.name
            << setw(15) << sensor.value
            << setw(20) << sensor.status
            << endl; 

        }
        cout << "\n====================================================\n";
        cout << " System Running - Real-Time Monitoring Active\n";
        cout << "====================================================\n";

        this_thread::sleep_for(chrono::milliseconds(5000));

    }
    return 0;

}