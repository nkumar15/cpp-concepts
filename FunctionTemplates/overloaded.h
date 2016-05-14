#ifndef OVERLOADED_H_INCLUDED
#define OVERLOADED_H_INCLUDED


/* Function 1 */
template<typename T>
const& T max(const T& a, const T& b){
    return a > b? a : b;
}

int max (int a, int b){
    return a > b : a ? b;
}

#endif // OVERLOADED_H_INCLUDED
