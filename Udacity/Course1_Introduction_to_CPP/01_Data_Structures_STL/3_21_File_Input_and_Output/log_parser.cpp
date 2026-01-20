/*
Instructions:

Open logs.txt using std::ifstream.

Read each line using std::getline(file, line).

Use a std::stringstream to split each line using , as the delimiter.

Store the parsed fields in:

    std::string timestamp

    std::string level

    std::string message

Print each part clearly.

If level is "ERROR", print "!!! This is an error."
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
