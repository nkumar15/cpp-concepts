#include <iostream>
#include <tuple>
using namespace std;

template<typename... T>
void show_args(T... args)
{
    int num_args = sizeof...(args);
    std::tuple<T...> tuple_(args...);

    cout<<std::get<0>(tuple_);
    cout<<std::get<1>(tuple_);
    cout<<std::get<2>(tuple_);

}



int main()
{
    cout << "Hello world!" << endl;
    show_args(1,2.3,"Hello");
    return 0;
}
