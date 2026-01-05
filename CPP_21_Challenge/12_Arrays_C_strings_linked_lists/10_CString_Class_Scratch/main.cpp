#include <iostream>
#include <cstring>

using namespace std;

class String{
    public:
        // constructors
        String();  
        String(const char * const); 
        String (const String &); 

        // operator overloading
        char & operator[] (unsigned short offset); 
        char operator[] (unsigned short offest) const; 
        String operator+ (const String &); 
        void operator+= (const String &); 
        String & operator= (const String &); 

        // General access methods
        unsigned short GetLen()const{ return itsLen; }
        const char * GetString() const { return itsString; } 

        // destructor
        ~String();

    private:
        // Private constructor
        String(unsigned short); 

        char * itsString; 
        unsigned short itsLen; 
};

// default constructor, it creates a string of 0 bytes
String::String(){
    itsString = new char[1]; 
    itsString[ 0] = '\0';
    itsLen = 0; 
}

// private constructor, it will be used only by
// the methods from the class to create a new class with
// the required size full of null characters
String::String(unsigned short len){
    itsString = new char[ len + 1 ];
    
    for(unsigned short i = 0; i <= len; i++){
        itsString[ i ] = '\0'; 
    }

    itsLen = len; 
}

// Converts a char array into string
String::String(const char * const cString){
    itsLen = strlen(cString); 
    itsString = new char[ itsLen + 1 ]; 

    for( unsigned short i = 0; i < itsLen; i++){
        itsString[ i ] = cString[ i ]; 
    }

    itsString[ itsLen ] = '\0';
}

// copy constructor
String::String(const String &rhs){
    itsLen  = rhs.GetLen(); 
    itsString =new char[ itsLen + 1 ]; 
    
    for(unsigned short i = 0; i < itsLen; i++){
        itsString[i] = rhs[i];
    }
    itsString[itsLen] = '\0';
}

// destructor
String::~String(){
    delete [] itsString; 
    itsLen = 0;
}

// equality operator overloading, frees the current memeory
// copies the chain ahd the string
String & String::operator= (const String & rhs){
    if (this == &rhs)
        return *this; 

    delete [] itsString; 
    itsLen = rhs.GetLen(); 
    itsString = new char[ itsLen + 1 ];
    for(unsigned short i = 0; i < itsLen ; i++){
        itsString[i] = rhs[i]; 
    }
    itsString[itsLen] = '\0'; 
    return *this; 
}

// non constant displacement operator. 

char  String::operator[](unsigned short offset) const{
    if( offset > itsLen){
        return itsString[ itsLen -1]; 
    }else{
        return itsString[ offset];
    }
}


// creates a new chain and concatenates the current rhs chain
String String::operator+(const String &rhs){
    unsigned short totalLen = itsLen + rhs.GetLen(); 
    String temp(totalLen); 
    unsigned short i; 

    for(i = 0; i < itsLen; i++)
        temp[ i ] = itsString[ i ]; 
    for(unsigned short j = 0; j < rhs.GetLen(); j++ , i++)
        temp[ i ] = rhs[ i - itsLen];
    temp[ totalLen ] = '\0'; 
    *this = temp;
}

int main(){
    String s1("initial test");
    cout << "s1: \t" << s1.GetString() << endl; 
}