#include <iostream> 

using namespace std; 

typedef int SPANS; 

enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

class Animal{
    private:
        int lAge;
    public:
        Animal(int); 
        virtual int  GetAge() const {return this->lAge;}
        virtual void SetAge(int age) {this->lAge = age;}
}; 

Animal::Animal(int age):lAge(age){
    cout << "ANIMAL : CONSTRUCTOR" << endl; 
}

class Horse : public Animal{
    protected:
        SPANS lHeight;
        COLOR lColor;
    public:
        Horse(COLOR color, SPANS height, int age);
        virtual ~Horse() {cout << "HORSE : DESTRUCTOR" << endl;} 
        virtual void Neigh() const { cout << "HORSE : NEIGH \n";}
        virtual SPANS GetHeight() const {return lHeight;}
        virtual COLOR GetColor() const {return lColor;}
};

Horse::Horse(COLOR color, SPANS height, int age):Animal(age),lColor(color),lHeight(height)
{
    cout << "HORSE: CONSTRUCTOR \n" ;
}

class Bird : public Animal{
    protected:
        COLOR lColor; 
        bool  lMigrate;

    public: 
        Bird(COLOR color, bool migrate, int age);
        virtual ~Bird(){ cout << "BIRD : DESTRUCTOR\n";}
        virtual void Chirp() const {cout << "BIRD : CHIRPING" << endl;}
        virtual void Fly() const { cout << "BIRD : FLYING \n"; }
        virtual COLOR GetColor() {return this->lColor;}
        virtual bool GetMigrate() {return this->lMigrate;} 
};

Bird::Bird(COLOR color, bool migrate, int age):
Animal(age),
lColor(color),
lMigrate(migrate){
    cout << "BIRD : CONSTRUCTOR " << endl;
}

class Pegasus : public Horse, public Bird{
    private:
        long lNoBelievers;
    public:
        void Chirp() const { cout << "PEGASUS : NEIGH" << endl; } 
        Pegasus(COLOR, SPANS, bool, long, int); 
        virtual ~Pegasus(){cout << "PEGASUS : DESTRUCTOR\n" << endl;}
        virtual long GetNoBelievers() const { return this->lNoBelievers;}
        virtual COLOR GetColor() const {return this->Horse::lColor;}
        virtual int GetAge() const {return this->Horse::GetAge();}
};

Pegasus::Pegasus(
    COLOR aColor,
    SPANS aHeight,
    bool  aMigrate, 
    long  aNoBelievers,
    int   aAge
):Horse(aColor, aHeight, aAge),
Bird(aColor, aMigrate, aAge),
lNoBelievers(aNoBelievers){
    cout << "PEGASUS : CONSTRUCTOR " << endl; 
};


int main(){
    Pegasus *apPegasus = new Pegasus(Red, 5, true, 10, 2);
    int age = apPegasus->GetAge(); 
    cout << "This pegasus is: " << age << " years old." << endl; 
    delete apPegasus; 
    return 0;
}