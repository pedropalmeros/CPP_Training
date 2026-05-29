#include <iostream> 
#include <stdexcept>
#include <cstring> 
#include <cstdio>

using namespace std; 

struct FileStats{
    size_t bytesWritten; 
    int writeCount;
}; 

class FileWriter{
    private:
        FILE* file;         // C-stye file handle
        FileStats* info;    // Track stats dynamically
        char* filename;     // Store filename dynamically

    public:
        FileWriter(const char* name) : file(nullptr), info(nullptr), filename(nullptr){
            if(!name) throw invalid_argument("Invalid filename: nullpointer"); 

            size_t length = strlen(name);
            if(length==0) throw invalid_argument("Invalid filename: empty string"); 

            filename = new char[length + 1]; 
            strcpy(filename, name); 

            file = fopen(filename,"w"); 
            if(!file){
                delete[] filename;
                throw runtime_error("Failed to open file"); 
            }

            info = new FileStats{0,0}; 
            cout << "FileWritter constructed for " << filename << "\n"; 
        }

        // Destructor releases resources
        ~FileWriter(){
            if(file){
                fclose(file); 
                file = nullptr;
            }
            delete info; 
            delete[] filename;
            cout << "FileWriter destroyed\n"; 
        }

        // Write a message to the file
        void write(const char* message){
            if(!file) throw runtime_error("File not open"); 
            fputs(message, file); 
            fputs("\n",file); 
            info->bytesWritten += strlen(message); 
            info->writeCount++; 
        }

        // print file statistics
        void outputStats() const {
            cout << "Bytes written: " << info->bytesWritten
                 << ", Write count: " << info->writeCount << endl; 
        }
};


int main(){
    try{
        FileWriter writer("demo.txt"); 
        writer.write("Hello, world"); 
        writer.write("RAII makes resourse management easy."); 
        writer.outputStats(); 
    }
    catch(const exception& e){
        cerr << "Error: " << e.what() << "\n"; 
    }
    return 0;
}