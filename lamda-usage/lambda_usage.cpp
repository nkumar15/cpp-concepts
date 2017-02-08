#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>


class Series {

private:
  std::vector<int> series;

public:
  Series(std::vector<int> v):series(v) {

    /*lamda function is used as unary function 
      it accepts the value from vector by reference 
      and increments it 
      capture list is default and doesn't have any usage here 
    */
    for_each(series.begin(),series.end(),[](int &n) { n++; } );
  }
   
  void show() {

    for(auto &v : series)
      std::cout << v << std::endl;
  }

  void show_thru_lambda() {

    /* for a non static member variable and function to be accessed for 
       lambda function. this is requried to capture */
    auto s_m = [this]() { for(auto &v : this->series)
                    std::cout << v << std::endl; };
    s_m(); 
    
    auto s_f = [this]() { this->show(); };
    s_f(); 
  }

};

int main() {

  std::vector<int> v{1,2,3,4};
  Series s(v);
 
  //s.show();
  //s.show_thru_lambda();

  /* generic lambda only supported in C++ 14 onwards */
  //auto sum = [](auto a , auto b ) { std::cout << a+b << std::endl; };
  //sum(1,2);
  //sum(2.3,4.5);


  /* init captures only supported in C++14 onwards */
  auto series_ptr = std::make_unique<Series>(v);
  series_ptr->show();
  auto show = [ ptr = std::move(series_ptr)] () { ptr->show(); };
  show();

  /* below line casues segfault as it is moved previously */
  //series_ptr->show();

  return 0;
  
}
