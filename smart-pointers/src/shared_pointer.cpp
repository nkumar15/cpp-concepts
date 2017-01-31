#include "../include/book.h"


void wrapper_show_book_by_val(shared_ptr<Book> ptr){
    /* Reference count should be 1 here */
    cout<<ptr.use_count()<<endl;
}

void wrapper_show_book_by_ref(shared_ptr<Book> &ptr){
    /* Reference count should be 2 here */
    cout<<ptr.use_count()<<endl;

}


void test_shared_pointer(){

    shared_ptr<Book> ptr(nullptr);
    {
        shared_ptr<Book> ptr1 (new Book("C++ Concepts",1234));

        /* Reference count should be 1 here */
        cout<<ptr1.use_count()<<endl;
        {
            /* Reference count should be 2 here */
            shared_ptr<Book> ptr2 = ptr1;
            cout<<ptr2.use_count()<<endl;
        }

        /* Reference count should be 1 here */
        cout<<ptr1.use_count()<<endl;

        /* Passing a unique pointer as reference is allowed and no ownership transfer happens */
        wrapper_show_book_by_ref(ptr1);

        /* Passing a unique pointer as by value is allowed and it made ownership transfer. Alarm.. */
        wrapper_show_book_by_val(ptr1);

        /* Reference count should be 1 here */
        cout<<ptr1.use_count()<<endl;
    }
}
