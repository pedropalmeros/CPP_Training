#include <iostream> 

using namespace std;

void change(int &x, int &y);

int main(){
    int x = 5, y = 10;

    cout << " main(). Before changing variables, x: " << x << " y: "  << y << endl << endl; 
    
    change(x,y); 

    cout << " main(). After changing variables, x: " << x << " y: "  << y << endl << endl; 

}


void change(int &x, int &y){
    int temp;

    cout << "Change(). Before changing variables, x: " << x << " y: " << y<< endl;  

    temp = x; 
    x = y;
    y = temp; 

    cout << "Change(). After changing variables, x: "  << x << " y: " << y << endl << endl;  
}