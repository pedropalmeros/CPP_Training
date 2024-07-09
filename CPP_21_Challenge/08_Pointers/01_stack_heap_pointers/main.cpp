
/***************************************************************************************************
 * NEW - this word is used to assign mememory in the heap. After the 'new' follows the object type
 * to be assigned, so the compiler can figure out the size of memory to be assigned. 
 * 
 * DELETE - after using the memory, the 'delete' has to be used to release and clean the memory. 
 ***************************************************************************************************/
#include <iostream> 

using namespace std;

int main(){
    int localVar = 5; 
    int * apLocal = &localVar; 
    int * apHeap = new int; 

    *apHeap = 7; 
    cout << "localVar: " << localVar << endl;
    cout << "*apLocal: " << *apLocal << endl; 
    cout << "*apHeap: "  << *apHeap << endl; 

    delete apHeap;

    apHeap = new int; 
    *apHeap = 9; 
    cout << "*apHeap: " << *apHeap << endl; 
    delete apHeap; 

    return 0; 


}

using namespace std; 