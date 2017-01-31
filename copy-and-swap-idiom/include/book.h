#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>

using namespace std;

class Book{
    char *name;
    int isbn;
public:
    Book(char *name,int isbn);
    Book(Book &other);
    void operator=(Book &other);
    ~Book();
    void to_string();
};


#endif // BOOK_H_INCLUDED
