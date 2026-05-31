#include<iostream>
#include <string>

using namespace std; 

class Battery{
    private:
        int percent;
    public:
        Battery();
        Battery(int aPercentage):percent{aPercentage}{
            cout << "Battery constructed ("<<percent<<"%)"<< endl;
        }
        int level() const{ return percent;}
        ~Battery(){
            cout << "Battery destroyed at "<< percent << "%" << endl; 
        }
};

class Scooter{
    private:
        Battery b;   // has-a Battery (member constructed before Scooter body)
        std::string model;
    public:
        // TODO: init battery with 'start', model with 'm', the print: Scooter
        Scooter(std::string m, int start):b(start),model(m){
            cout << "Scooter("<<model<<") constructed" << endl; 
        }
        // TODO: print: <model> battery: <level>%
        void status() const{
            cout << model << " battery: " << b.level() << "%\n"; 
        }

        // TODO: print: Scooter(<model>) destroyed  
        ~Scooter(){
            cout << "Scooter ("<< model << ") destroyed" << endl; 
        } 
};

int main(){
    cout << "-------------------------------------\n";
    std::cout << "Start\n"; 
    {
        Scooter s("Mini", 80);
        s.status();
    }
    std::cout <<"Done\n";

    return 0; 
}