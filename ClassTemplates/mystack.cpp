#include "mystack.h"

/*Specialized template for string type */
template<>
class MyStack<std::string>{

public:
    void push(const std::string& elem);
    void pop();
    std::string top();

private:
    bool is_empty();
    /* Using deque for string. It will perform better */
    /* Just an example for optimization */
    /* deque frees up to memory on deletion of node unlike vector */
    std::deque<std::string> elems;
};

bool MyStack<std::string> :: is_empty(){
    return elems.empty();
}

void MyStack<std::string> :: push(const std::string& elem){
    elems.push_back(elem);
}

void MyStack<std::string> :: pop(){
    if( !is_empty() )
        elems.pop_back();
    else
        cout<<"Stack is empty.";
}

std::string MyStack<std::string> :: top(){
    if( !is_empty() ){
        return elems.back();
    }
    else
        cout<<"Stack is empty.";
}


void test_string_stack(){
    MyStack<std::string> stack1;

    stack1.push("India");
    stack1.push("Singapore");
    stack1.push("United States");

    cout<<stack1.top()<<endl;
    stack1.pop();

    cout<<stack1.top()<<endl;
    stack1.pop();

    cout<<stack1.top()<<endl;
    stack1.pop();
}


void test_int_stack(){
    MyStack<int> stack1;

    stack1.push(11);
    stack1.push(10);
    stack1.push(12);

    cout<<stack1.top()<<endl;
    stack1.pop();

    cout<<stack1.top()<<endl;
    stack1.pop();

    cout<<stack1.top()<<endl;
    stack1.pop();
}
