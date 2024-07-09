#include <iostream> 

using namespace std; 

class Rectangle{
    private:
        int lWidth; 
        int lHeight; 

    public: 
        Rectangle();
        ~Rectangle(); 

        void putHeight(int); 
        int getHeight();

        void putWidth(int);
        int getWidth();
};

Rectangle::Rectangle(){
    this->lWidth = 10; 
    this->lHeight = 5; 
}

Rectangle::~Rectangle(){}

void Rectangle::putHeight(int height){
    this->lHeight = height;
}

int Rectangle::getHeight(){
    return this->lHeight;
}

int Rectangle::getWidth(){
    return this->lWidth;
}

void Rectangle::putWidth(int width){
    this->lWidth = width;
}