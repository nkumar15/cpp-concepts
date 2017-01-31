#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
 T const& max(const T& a, const T& b){
    cout<<"Template called " << typeid(T).name()  <<endl;
    return a > b ? a : b;
}

int max (int a, int b){
    cout<<"Non template called "<<endl;
    return a > b ? a : b;
}


template<typename T>
T const&  max(const T& a,const T& b, const T&c){
    cout<<"Template 3 args called "<<endl;
    return ::max(::max(a,b),c);
}


int main()
{
::max(1,2);        /* calls the non template int version function */

::max(1.1,2.2);  /* calls the template double version (by argument deduction) */

::max('a','b');     /* calls the template char version (by argument deduction) */

::max(1,2,3);    /* calls the template int version for 3 ints (by argument deduction) */

::max<>(1,2);   /* calls the template int version (by argument deduction) */

::max<float>(1.2,1.3);  /* calls the template float version (no argument deduction) */

}
