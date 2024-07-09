#include <iostream>

using namespace std; 

class Rectangle{
    private:
        int rHeight;
        int rWidth;
    public: 
        Rectangle();
        ~Rectangle();
        void setWidth(int aWidth);
        int getWidth() const;
        void setHeight(int aHeight);
        int getHeight() const; 
};

Rectangle::Rectangle(){
    this->rHeight = 5;
    this->rWidth = 10;
}

Rectangle::~Rectangle(){}

void Rectangle::setWidth(int aWidth){
    this-> rWidth = aWidth;
}

int Rectangle::getWidth()const{
    return this-> rWidth;
}

void Rectangle::setHeight(int aHeight){
    this->rHeight = aHeight;
}

int Rectangle::getHeight() const{
    return this->rHeight;
}