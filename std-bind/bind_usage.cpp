#include<iostream>
#include<functional>

class A {

public:
  void show() {
    std::cout << "Hello" << std::endl;
  }
};


void sum(int a, int b) {
  std::cout << a+b << std::endl;
}

int main()  {

  /* binding a member function
     address of function should be passed 
     obj can be passed like a or &a.
     function and object are compulsary parameters
  */
  A a;
  std::bind(&A::show,&a)();

  /* place holders used to mention the position of 
     argument in function call
  */
  using namespace std::placeholders;
  auto f = std::bind(sum,1,_1);
  f(9);
 
  return 0;
}




