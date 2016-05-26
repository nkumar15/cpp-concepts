#include <iostream>
#include <future>
#include <chrono>

using namespace std;

bool is_prime(int num)
{
    for(int i=2; i<num; i++)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    std::future<bool> fut = std::async(is_prime,15);
    cout << "Main Program message" << endl;
    std::chrono::milliseconds span(100);

    //while(fut.wait_for(span) == std::future_status::timeout )
    //    cout<<"."<<std::flush;

    bool prime =  fut.get();

    if(prime)
        cout<<"Number is prime"<<endl;
    else
        cout<<"Number is not prime"<<endl;

    return 0;
}
