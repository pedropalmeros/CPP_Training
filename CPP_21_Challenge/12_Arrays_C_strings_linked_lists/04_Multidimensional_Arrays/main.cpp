/**************************************************************************************************************************
 * In C++ and it is possible to have arrays of multiple dimensions. Each dimension is represented as a subindex of the array.
 * Hence, in a two dimensional array, there are two subindices. 
 * 
 * The
 */

#include <iostream>

using namespace std; 

int main()
{
    int anArray[5][2] = {{0,0},{1,2},{2,4},{3,6},{4,8}};

    for (int i= 0; i < 5; i++){
        for(int j =0; j < 2; j++){
            cout << "anArray["<< i << "][" <<j<<"]: " << anArray[i][j] << endl;
        }
    }

    return 0;
}