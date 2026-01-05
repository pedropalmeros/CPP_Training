#include <iostream> 
#include <string> 

int main(int argc, char* argv[]){
    // argc holds the number of arguments (including the program name)
    // argv is an array of character pointers, where each pointer points to an argument string. 

    std::cout << "Program name is: " << argv[0] << std::endl; 

    if(argc==1){
        std::cout << "No aditional arguments passed" << std::endl; 
    }else{
        std::cout << "Number of arguments passed (excluding program name): " << argc-1 << std::endl; 
        std::cout << "Following are the arguments: " << std::endl; 

        // Loop through arguments starting from the index 1 
        // index 0 is the program name 
        for (int i =1; i <argc; i++){
            // Treat argv[i] as a string
            std::string arg = argv[i]; 
            std::cout << "Argument " << i << arg << std::endl;
        }
}

return 0; 
}