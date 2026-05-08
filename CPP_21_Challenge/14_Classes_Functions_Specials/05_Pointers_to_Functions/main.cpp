#include <iostream> 

using namespace std; 

void Square(int&, int&); 
void Cube(int&, int&); 
void Swap(int&, int&); 
void GetValues(int&, int&); 
void PrintValue(int, int);

int main(){
    void (*apFunc)(int&, int&); 
    bool fQuit = false; 

    int valOne = 1, valTwo = 2; 
    int option; 

    while(fQuit == false){
        cout << "(0)Quit (1)Get Values  (2)Square  (3)Cube   (4)Swap: ";
        cin >> option; 
        switch(option){
            case 1: apFunc = GetValues; break; 
            case 2: apFunc = Square; break;
            case 3: apFunc = Cube; break; 
            case 4: apFunc = Swap; break; 
            default : fQuit = true; break;
        }

        if(fQuit){
            break; 
        }

        PrintValue(valOne, valTwo);
        apFunc(valOne, valTwo); 
        PrintValue(valOne, valTwo);
    }

    return 0;
}

void PrintValue(int x, int y){
    cout << "x: " << x << "   y: " << y << endl; 
}

void Square(int &rX, int &rY){
    rX *= rX; 
    rY *= rY;
}

void Cube(int &rX, int &rY){
    int tmp;
    tmp = rX; 
    rX *= rX; 
    rX *= rX * tmp;

    tmp = rY; 
    rY *= rY; 
    rY *= rY * tmp;
}


void Swap(int &rX, int &rY){
    int temp; 
    temp  = rX; 
    rX = rY; 
    rY = temp; 
}

void GetValues(int & rValOne, int & rValTwo){
    cout << "New Value for valOne: ";
    cin >> rValOne; 
    cout << "New Value for valTwo: "; 
    cin >> rValTwo;
}