#include <iostream>

using namespace std; 

int main(){
    // define MONTHS as having 12 possible values
    enum MONTHS {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

    // define bestMonth as variable
    MONTHS bestMonth;

    // Assign bestMonth as a variable type MONTHS
    bestMonth = Jan; 

    // Now we can check the value of bestMonths just 
    // like any other variable
    if (bestMonth == Jan){
        cout << "I'm not so sure January is the best month: " << bestMonth << endl; 
    }
    
    return 0;
}