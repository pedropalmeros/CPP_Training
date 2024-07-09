/*************************************************************
 * Goal: practice using multimensional arrays.
 * Write a program that will accept values for a 4x4 array
 * and vector of size 4
 * Use the dot product to multiply the array by the vector
 * Print the resulting vector. 
 *************************************************************/

#include <iostream>

using namespace std; 

int main(){
    // TODO: multiply a 4x4 array with vector of size 4.
    // Print the resultant product vector. 

    int vectorData[4] = {0,0,0,0};

    int matrixData[4][4] = {0};

    int resultantVector[4] = {0};

    // READING vector data
    for(int i=0; i<4; i++){
        cout << "Introduce the vector[" <<i <<"] value: ";
        cin >> vectorData[i];
    }

    // PRINTING the vector data
    for(int i=0; i<4; i++){
        cout << "vector[" <<i <<"]: " << vectorData[i] << endl; 

    }

    // READING Matrix data
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << "Introduce A["<< i<< "][" << j<< "]: ";
            cin >> matrixData[i][j];
        }
    }

    // PRINT Matrix data
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << matrixData[i][j];
            cout << " ";
        }
        cout << endl; 
    }

    // PRODUCT
    int sum = 0;
    for (int i=0 ; i<4; i++){
        for (int j=0; j<4; j++){
            cout << "Vector[" << j << "] = " << vectorData[j] << endl;
            cout << "Matrix[" << j<< " ][" << i<< "] = " << matrixData[j][i] << endl; 
            resultantVector[i] = resultantVector[i] + vectorData[j]*matrixData[j][i];
        }
    }

    // PRINTING RESULTING VECTOR
    cout << "PRINTING RESULTING VECTOR" << endl << endl; 
    cout << "V = [";
    for(int i=0; i<4; i++){
        cout << resultantVector[i] << " ";
    }
    cout << " ]" << endl << endl; 

    return 0; 
}