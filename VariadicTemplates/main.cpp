#include <iostream>
#include <tuple>
using namespace std;

template<typename T>
void show_args(T &val)
{
    cout<<val<<" ";
}


template<typename U, typename... T>
void show_args(U val, T... args)
{
    //int num_args = sizeof...(args);
    cout<<val <<" ";
    show_args(args...);
}

int main()
{
    show_args(1,2.3,3.4f,"Hello");
    return 0;
}


/* Explaination */
/*
Value 1 is being passed to val (U val) in function
2.3, 3.4 and hello are passed as variadic arguments
so again variadic show_args gets called in which val becomes 2.3 and 3.4 and hello becomes args
This cycle continues until it reaches last case when it is left with 1 argument hello */

