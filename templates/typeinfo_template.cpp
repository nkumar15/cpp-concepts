#include <iostream>
#include <typeinfo>

template<typename T1, typename T2>
void sum(T1 a, T2 b) {
 std::cout << typeid(b).name();
 std::cout << a  << std::endl;
}

int main()
{
   sum<int>(1.1,1.4);
   return 0;
}
