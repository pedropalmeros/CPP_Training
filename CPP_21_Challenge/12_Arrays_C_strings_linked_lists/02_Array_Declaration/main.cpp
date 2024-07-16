/**********************************************************************************************
 * The arrays can be declared and initalized with
 * int myArray[5] = {1,2,3,4,5};
 * or
 * int myArray[] = {1,2,3,4,5};
 */

#include <iostream>
using namespace std; 

int main(){
    enum WeekDays {Sun, Mon, Tue, Wen, Thr, Fri, Sat, dayWeek};

    int weekArr[dayWeek] = {10, 20, 30, 40, 50, 60, 70};

    cout << "The valoue of the Thursday is: " << weekArr[Thr] << endl; 

    return 0; 
}