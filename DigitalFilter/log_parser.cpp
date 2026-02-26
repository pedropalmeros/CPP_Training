
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std; 

class Filter{
    private:
        int windowSize; 
        char initMethod;
        vector<double> data;

    public:
        Filter();
        Filter(int awindowSize);
        Filter(int awindowSize, char ainitMethod);
        double UpdateFilter(double aValue); 
        void Initialize(double value);
};

Filter::Filter():windowSize(1),initMethod('1'){}

Filter::Filter(int awindowSize):windowSize(awindowSize),initMethod('1'){}

Filter::Filter(int awindowSize, char ainitMethod):windowSize(awindowSize),initMethod(ainitMethod){}

void Filter::Initialize(double value){
    if (this->initMethod == '0'){
        data.push_back(value);
        for(int i = 0; i <= windowSize-1;i++){
            data.push_back(value);
        }
    }
    else{
        for(int i = 0; i <= windowSize; i++){
            data.push_back(value);
        }
    }
}

double Filter::UpdateFilter(double aValue){
    if(data.size()==0){
        Initialize(aValue);
    }

    for(int i = 0; i<data.size(); i++){

    }

    return 0.0;
}


int main() {
    std::ifstream file("logs.txt");
    if (!file) {
        std::cerr << "Could not open log file." << std::endl;
        return 1;
    }

    std::string line;

    // TODO: Use the proper parameters for the while loop to read the file until the last line
    while (std::getline(file,line)) {
        std::stringstream ss(line);
        std::string timestamp, level, message;


        // TODO: Use std::getline with delimiter ',' to extract each token
        std::getline(ss,timestamp,',');
        std::getline(ss,level,','); 
        std::getline(ss,message,',');
        // TODO: Print timestamp, level, message

        std::cout << "Timestamp: " << timestamp << std::endl; 
        std::cout << "Level: " << level << std::endl;
        std::cout << "Message: " << message << std::endl; 

        if(level == "ERROR"){
            std::cout << "BE CAREFUL THERE IS AN ERROR " << std::endl; 
        }


        // TODO: If level is ERROR, print extra warning

        std::cout << "----------------------\n";
    }

    return 0;
}
