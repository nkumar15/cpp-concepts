#include "../include/book.h"


void wrapper_show_book_by_val(auto_ptr<Book> ptr){
    ptr->to_string();
}

void wrapper_show_book_by_ref(auto_ptr<Book> &ptr){
    ptr->to_string();
}


void test_unique_pointer(){

    auto_ptr<Book> ptr;
    {
        auto_ptr<Book> ptr1 (new Book("C++ Concepts",1234));
        ptr1->to_string();

        {
            /* Code compiled. Ownership transfered silently.  */
            /* Looks like two auto_ptr instances can manage the same object. */
            auto_ptr<Book> ptr2 = ptr1;
            ptr2->to_string();
        }

        /* Now if you want to use ptr1 it will sigsegv. */
        /* the previous ptr2 has released the object*/
        //ptr1->to_string();


        /* Passing a unique pointer as reference is allowed and no ownership transfer happens */
        auto_ptr<Book> ptr(new Book("C Concepts",1235));
        wrapper_show_book_by_ref(ptr);
        ptr->to_string();

        /* Passing a unique pointer as by value is allowed and it made ownership transfer. Alarm.. */
        wrapper_show_book_by_val(ptr);
        //ptr->to_string();   / *This code will throw sigsegv in runtime */
    }
}
