/*
You're building a simple eBook reader app. Each book needs to store and manage its own information.

Your task is to design a Book class that:

    Stores:

        The book's title

        The author

        The pageCount

    Uses private member variables

    Uses public setter and getter methods to interact with those variables

After building the class, create a few Book objects in main() and demonstrate how to set and 
get their information.
*/

#include <iostream>
#include <string>

class Book {
    // TODO: Declare private member variables: title, author, pageCount
private:
    std::string title;
    std::string author;
    int pageCount;

public:
    // TODO: Write setter methods: setTitle, setAuthor, setPageCount
    void setTitle(const std::string& t){title = t;}
    void setAuthor(const std::string& a){author = a;}
    void setPageCount(int pages){pageCount = pages;}


    // TODO: Write getter methods: getTitle, getAuthor, getPageCount

    std::string getTitle()  {return title;}
    std::string getAuthor()  {return author;}
    int getPageCount()  {return pageCount;}
};

int main() {
    // Create book objects
    Book b1, b2;

    // TODO: Use setters to assign book data
    // TODO: Use getters to print book details

    b1.setTitle("The Pragmatic Programmer");
    b1.setAuthor("Andy Hunt");
    b1.setPageCount(352);

    b2.setTitle("Clean Code");
    b2.setAuthor("Robert C. Martin");
    b2.setPageCount(464);

    std::cout << "Book 1:\n";
    std::cout << "Title: " << b1.getTitle() << "\n";
    std::cout << "Author: " << b1.getAuthor() << "\n";
    std::cout << "Pages: " << b1.getPageCount() << "\n\n";

    std::cout << "Book 2:\n";
    std::cout << "Title: " << b2.getTitle() << "\n";
    std::cout << "Author: " << b2.getAuthor() << "\n";
    std::cout << "Pages: " << b2.getPageCount() << "\n";

    return 0;
}

/*
Expected output:
Book 1:
Title: The Pragmatic Programmer
Author: Andy Hunt
Pages: 352

Book 2:
Title: Clean Code
Author: Robert C. Martin
Pages: 464
*/