/***************************************************************************************************************
 * The constructor that is offered by the compiler is known as predetermined constructor but any consturctor
 * without parameters is known as default or predetermined.
 * As other methods, constructor can be overloaded. 
 ***************************************************************************************************************/

#include <iostream> 

using namespace std; 

class Rectangle{
    private:
        int lWidth; 
        int lHeight;
    public:
        Rectangle(); 
        Rectangle(int aWidth, int aHeight);
        int getWith() const; 
        int getHeight() const; 
};

Rectangle::Rectangle(){
    lWidth = 10; 
    lHeight = 5; 
}

Rectangle::Rectangle(int aWidth, int aHeight){
    this->lWidth = aWidth; 
    this->lHeight = aHeight; 
}

int Rectangle::getWith() const{
    return lWidth;
}

int Rectangle::getHeight() const{
    return lHeight;
}

int main(){
    int userWidth;
    int userHeight; 
    Rectangle Rect01;
    cout << "Rect01 Width: "  << Rect01.getWith() << endl; 
    cout << "Rect01 Height: " << Rect01.getHeight() << endl; 


    cout <<"Introduce a new Width: ";
    cin >> userWidth; 

    cout << "Introduce a new Height: ";
    cin >> userHeight; 

    Rectangle Rect02(userWidth, userHeight);
    cout << "Rect02 Width: "  << Rect02.getWith() << endl; 
    cout << "Rect02 Height: " << Rect02.getHeight() << endl; 

    return 0; 
}