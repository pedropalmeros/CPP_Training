/*******************************************************************************
 * Find the min and the max and average of 15 numbers that a user will input
 * The numbers range from 0 to 100
 * We will do it now for practice and again later when we learn arrays and 
 * functions. So you do not have to keep all fifteen numbers stored in memory. 
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int getMax(int, int);
int getMin(int, int);

int main(){
    int number = -1; 
    int min = 100;
    int max = 0; 
    float average; 
    int summatory = 0; 

    for(int i = 1; i <= 15; i ++){
        cout << "Reading number: "  << i << endl; 
        do {
            cout << "Introduce a number (0-100): " ; 
            cin >> number; 
        }while(!(number >=0 && number <=100));
        
        summatory += number;
        min = getMin(min, number);
        max = getMax(max, number);
    }

    average = float(summatory)/15.0;

    cout << "Average: "  << average << endl; 
    cout << "Min: "  << min << endl; 
    cout << "Max: "  << max << endl; 

    return 0;
}
int getMax(int a, int b){
    if(a >= b){
        return a; 
    }
    else{
        return b;
    }
}

int getMin(int a, int b){
    if(a <= b){
        return a; 
    }
    else{
        return b; 
    }
}