#include <iostream>

using namespace std;

class Rectangle{
    public: 
        Rectangle(int aHeight, int aWidth);
        ~Rectangle();
        void DrawFigure(); 
        void DrawFigure(int aHeight, int aWidth); 
    private:
        int lHeight; 
        int lWidth; 
};

Rectangle::Rectangle(int aHeight, int aWidth){
    this->lHeight = aHeight;
    this->lWidth = aWidth;
}

Rectangle::~Rectangle(){}

void Rectangle::DrawFigure() {
    DrawFigure(lHeight, lWidth);
}

void Rectangle::DrawFigure(int aHeight, int aWidth){
    for(int i = 0; i < aHeight; i++){
        for(int j = 0; j < aWidth; j++){
            cout << "*" ;
        }
        cout << endl; 
    }

}