#include "../include/book.h"

void wrapper_show_book(unique_ptr<Book> ptr){
    ptr->to_string();
}

void wrapper_show_book_by_ref(unique_ptr<Book> &ptr){
    ptr->to_string();
}


void test_auto_pointer(){

    unique_ptr<Book> ptr;
    {
        unique_ptr<Book> ptr1 (new Book("C++ Concepts",1234));
        ptr1->to_string();

        /* Code won't compile. No ownership transfer */
        /* No two unique_ptr instances can manage the same object. */
        //unique_ptr<Book> ptr2 = ptr1;

        /* But if you really want to move the resource go with move semantics */
        unique_ptr<Book> ptr2(std::move(ptr1));
        ptr2->to_string();

        /* Now if you want to use ptr1 it will sigsegv. Reason is the internal object
           in ptr1 has been set to nullptr */
        //ptr1->to_string();

        /* Now who ownes the ownership of underlying object ptr2 of this function or ptr in called function */
        /* so again below code won't compile. If you want to really transfer, use move semantic */
        /* Also passing a unique pointer as reference is allowed and no ownership transfer happens */

        wrapper_show_book_by_ref(ptr2);
        wrapper_show_book(std::move(ptr2));
    }
}
