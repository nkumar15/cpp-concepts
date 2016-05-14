#ifndef SAMETYPES_H_INCLUDED
#define SAMETYPES_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

void same_types();

/*Function 1*/
template <typename T>
T const & sum(const T& a , const T& b){
    return a + b;
}

#endif // SAMETYPES_H_INCLUDED
