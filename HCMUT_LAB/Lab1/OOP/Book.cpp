/*
Hoang is a K19 student studying at Bach Khoa University. He plans to write a book management software for the library. In the class design, Hoang has designed the class Book as follows:

class Book
{
private:
    char* title; 
    char* authors; 
    int publishingYear; 
public: 
   // some method
}
Your task in this exercise is to implement functions marked with * STUDENT ANSWER *.
Note: For exercises in Week 2, we have #include <bits/stdc++.h> and using namespace std;

For example:

Test	                                                        Result
Book book1("Giai tich 1","Nguyen Dinh Huy",2000);               Giai tich 1
book1.printBook();                                              Nguyen Dinh Huy
                                                                2000

Book book1("Giai tich 1","Nguyen Dinh Huy",2000);               Giai tich 1
Book book2 = book1;                                             Nguyen Dinh Huy
book2.printBook();                                              2000
*/

#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book() {
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book) {
        this->title = new char[strlen(book.title) + 1];
        strcpy(this->title, book.title);
        this->authors = new char[strlen(book.authors) + 1];
        strcpy(this->authors, book.authors);
        this->publishingYear = book.publishingYear;
    }

    void setTitle(const char* title) {
        delete[] this->title; 
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors) {
        delete[] this->authors; 
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear) {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const {
        return title;
    }

    char* getAuthors() const {
        return authors;
    }

    int getPublishingYear() const {
        return publishingYear;
    }

    ~Book() {
        delete[] title;
        delete[] authors;
    }

    void printBook() {
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main() {
    Book book1("Giai tich 1", "Nguyen Dinh Huy", 2000);
    book1.printBook();
    cout << endl;

    Book book2 = book1;
    book2.printBook();
    return 0;
}