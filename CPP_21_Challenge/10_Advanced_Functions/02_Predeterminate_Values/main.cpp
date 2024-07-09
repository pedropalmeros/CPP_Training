#include <iostream>

using namespace std; 

class Rectangle{
    private:
        int lWidth;
        int lHeight;
    public:
        Rectangle(int aWidth, int aHeight);
        ~Rectangle();
        void DrawFigure(int aWidth, int aHeight, bool aUseCurrentValues = false);
};

Rectangle::Rectangle(int aWidth, int aHeight){
    lWidth = aWidth; 
    lHeight = aHeight;
}

Rectangle::~Rectangle(){
    cout << "Destructor" << endl; 
}

void Rectangle::DrawFigure(int aWidth, int aHeight, bool aUseCurrentValues = false){
    int printWidth; 
    int printHeight; 
    if (aUseCurrentValues){
        printWidth = lWidth; 
        printHeight = lHeight; 
    }else{
        printWidth = aWidth; 
        printHeight = aHeight; 
    }

    for (int i = 0; i < printHeight; i++){
        for(int j=0; j< printWidth; j++){
            cout << "*";
        }
        cout << endl; 
    }
}



int main(){
    //
    Rectangle theRectangle(30,5);
    cout << "DrawFigure(0,0,true) ... "  << endl; 
    theRectangle.DrawFigure(0, 0, true); 
    cout << "DrawFigure(40,2)..." << endl; 
    theRectangle.DrawFigure(40,2);
    return 0;
}