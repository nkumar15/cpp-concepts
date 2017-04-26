#include <iostream>
#include <tuple>

using namespace std;

/*
Support
  from GCC 7 onwards
  from clang 4
  As of writing no support from VC
*/

std::tuple<string, bool> open()
{
    return {"", false};
}

int main()
{
    auto[msg, success] = open();
    if (success != true)
    {
        std::cout << "Open() failed.";
        return 1;
    }
    std::cout << msg;
    return 0;
}