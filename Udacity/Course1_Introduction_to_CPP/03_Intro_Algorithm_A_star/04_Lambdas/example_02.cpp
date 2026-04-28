#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Book {int pages;}; 


int main(){
    std::vector<Book> shelf = {{352},{464},{128}};

        std::for_each(shelf.begin(), shelf.end(),[](const Book &a){
        std::cout << "Book Number pages: " << a.pages << endl; 
    });


    // sort by pages ascending
    std::sort(shelf.begin(), shelf.end(),[](const Book &a, Book &b){
        cout << "Book A pages: " << a.pages << endl; 
        cout << "Book B pages: " << b.pages << endl; 
        cout << "---------------------"<< endl; 

        return a.pages < b.pages;
    });

    std::for_each(shelf.begin(), shelf.end(),[](const Book &a){
        std::cout << "Book Number pages: " << a.pages << endl; 
    });



    return 0;
}