/*
You're building a tool for engineers to inspect log output from a device. Here's a sample log line:
"[2025-07-14 10:15:32] ERROR: Camera stream failed to start"

You need to parse this string to extract:

    The timestamp

    The severity level (INFO, ERROR, WARN, etc.)

    The actual log message

Store the log line in a std::string.

Use .find() and .substr() to extract:

    The timestamp (between [ and ])

    The log level (between ] and :)

    The message (after the colon)

Print the extracted parts cleanly.

If the level is "ERROR", print a warning message (just prefix with !!!).
*/

#include <iostream>
#include <string>

using namespace std; 

std::string GetTimestamp(std::string logInfo){

    size_t openBracket = logInfo.find('[');
    size_t closeBracket = logInfo.find(']');

    std::string timeStamp = logInfo.substr(openBracket+1, closeBracket-1);

    return timeStamp;
}

std::string GetSeverityLevel(std::string logInfo){
    size_t closeBracket = logInfo.find(']')+2;
    size_t colonSymbol = logInfo.find(':',closeBracket+1); 

    std::string severityLevel = logInfo.substr(closeBracket, colonSymbol-closeBracket); 

    return severityLevel;
}

std::string GetMessage(std::string logInfo){
    size_t colonSymbol = logInfo.find(':'); 

    std::string message = logInfo.substr(colonSymbol+1);

    return message; 
    
}

int main() {
    std::string log = "[2025-07-14 10:15:32] ERROR: Camera stream failed to start";


    
    // TODO: Extract timestamp
    std::string Timestamp = GetTimestamp(log);
    cout << "main: Timestamp: " << Timestamp << endl; 

    // TODO: Extract log level
    std::string severityLevel = GetSeverityLevel(log); 
    cout << "main: severityLevel: " << severityLevel << endl; 

    // TODO: Extract message
    std::string message = GetMessage(log);
    cout << "main: message: " << message << endl; 

    // Print all parts (timestamp, log level, message)
    // If log level is "ERROR", print a warning prefix
    if (severityLevel == "ERROR"){
        cout << "!!!" << endl; 
    }

    return 0;
}
