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
/* int STACKSIZE is an example of NONType Class Template Parameters */
template<typename T, typename CONT = std::vector<T>, int STACKSIZE = 2>
class MyStack{
public:
    MyStack():SIZE(STACKSIZE){}
    void push(const T& elem);
    void pop();
    T top();

private:
    bool is_empty();
    bool is_full();
    int SIZE;
    CONT elems;

};

template<typename T, typename CONT,int STACKSIZE>
bool MyStack<T,CONT,STACKSIZE> :: is_empty(){
    return elems.empty();
}

template<typename T, typename CONT,int STACKSIZE>
bool MyStack<T,CONT,STACKSIZE> :: is_full(){
    return elems.size() == SIZE;
}

template<typename T, typename CONT,int STACKSIZE>
void MyStack<T,CONT,STACKSIZE> :: push(const T& elem){
    if(is_full()){
        cout<<"Stack is full."<<endl;
    }
    else
        elems.push_back(elem);
}

template<typename T, typename CONT,int STACKSIZE>
void MyStack<T,CONT,STACKSIZE> :: pop(){
    if( !is_empty() )
        elems.pop_back();
    else
        cout<<"Stack is empty.";
}

template<typename T, typename CONT,int STACKSIZE>
T MyStack<T,CONT,STACKSIZE> :: top(){
    if( !is_empty() ){
        return elems.back();
    }
    else
    {
        cout<<"Stack is empty.";
        return static_cast<T>(NULL);
    }


}

#endif // MYSTACK_H_INCLUDED
