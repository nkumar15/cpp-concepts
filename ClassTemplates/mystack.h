#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

void test_int_stack();
void test_string_stack();

/* Template default parameter */
/* if CONT type is not passed in template parameter
   then default std::vector<T> will be used */
template<typename T, typename CONT = std::vector<T>>
class MyStack{
public:
    void push(const T& elem);
    void pop();
    T top();

private:
    bool is_empty();
    CONT elems;
};

template<typename T, typename CONT>
bool MyStack<T,CONT> :: is_empty(){
    return elems.empty();
}

template<typename T, typename CONT>
void MyStack<T,CONT> :: push(const T& elem){
    elems.push_back(elem);
}

template<typename T, typename CONT>
void MyStack<T,CONT> :: pop(){
    if( !is_empty() )
        elems.pop_back();
    else
        cout<<"Stack is empty.";
}

template<typename T, typename CONT>
T MyStack<T,CONT> :: top(){
    if( !is_empty() ){
        return elems.back();
    }
    else
        cout<<"Stack is empty.";
}

#endif // MYSTACK_H_INCLUDED
