#include <iostream>
#include <functional>


void f1() {
  std::cout << "f1()" << std::endl;
}

void f2() {
  std::cout << "f2()" << std::endl;
}


int main() {

  std::function<void()>f(f1);
  f();
}

   
