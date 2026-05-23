#include <algorithm>
#include <vector> 

struct Book {int pages;}; 

int main(){

    std::vector<Book> shelf ={{352},{464}, {128}}; 

    // Sort by pages ascending
    std::sort(shelf.begin(), shelf.end(), [](const Book &a, const Book &b){
        return a.pages < b.pages;
    });

    return 0; 
}