#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string.h>
#include <memory>

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



void test_unique_pointer();
void test_auto_pointer();
void test_shared_pointer();
#endif // BOOK_H_INCLUDED
