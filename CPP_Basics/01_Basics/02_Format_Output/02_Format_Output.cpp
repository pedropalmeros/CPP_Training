#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    cout << "\n\nThe text without any formatting. \n";
    cout << "Ints" << "Floats" << "Doubles" << endl;
    cout << "\nThe text with setw(15)\n";
    cout << "Ints" << setw(15) <<"Floats"<<setw(15) << "Doubles" << "\n";
    cout << "\n\nThe text with tabs\n";
    cout << "Ints\t" << "Floats\t" << "Doubles" << "\n";

}