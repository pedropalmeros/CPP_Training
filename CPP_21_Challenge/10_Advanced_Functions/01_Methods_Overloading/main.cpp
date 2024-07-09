#include "rectangle.hpp"

int main(){
    // Beginning, creating a rectangle of 30,5 units
    Rectangle Rect01(30,5);
    cout << "DrawFigure() const: "  << endl; 
    Rect01.DrawFigure();
    cout << "DrawFigure(40,2): " << endl; 
    Rect01.DrawFigure(40,2);
    
    return 0; 
}