#include "../include/book.h"
#include <string.h>

Book :: Book(char *name,int isbn){
    int len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name,name);
    this->isbn = isbn;
}

Book :: Book(Book &other){
    isbn = other.isbn;
    char *temp_name = new char[strlen(other.name)];
    strcpy(temp_name,name);
    delete name;
    name = temp_name;
}

Book :: ~Book(){
    delete name;
    cout<<"Destructor called."<<endl;
}

void Book ::  to_string(){
    cout<<name<<":"<< isbn <<endl;
}

void Book :: operator=(Book &other){
    isbn = other.isbn;
    char *temp_name = new char[strlen(other.name)];
    strcpy(temp_name,name);
    delete name;
    name = temp_name;
}
