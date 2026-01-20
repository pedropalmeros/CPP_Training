/*
Your program is logging system errors but the error message is optional.

Implement a reportError message that utilizes pointers to model this and handle
errors that dont have an error message.

If message is not null, print "ERROR: <message>".

If message is null, print "No error message provided."
*/
#include <iostream>
#include <string>

// TODO: implement reportError

void reportError(std::string *msg){
    if(msg==nullptr){
        std::cout << "No error message provided\n"; 
    }else{
        std::cout << "ERROR: " << *msg;
    }
}

int main() {
    std::string msg = "Camera stream failed.\n";
    reportError(&msg);         // Should print error
    reportError(nullptr);      // Should handle gracefully
    return 0;
}
