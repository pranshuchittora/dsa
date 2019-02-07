#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
const unsigned long long total = 45;
unsigned long long fib(unsigned long long n)
{

    if (n <= 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (unsigned long long i = 1; i <= total; i++)
    {

        cout << i << " => " << fib(i) << endl;
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(t2 - t1).count();
    cout << endl
         << endl
         << "Execution Time -> " << (double)duration / 1000000 << " sec"
         << " | " << (double)duration / 1000 << " ms"
         << " | " << (double)duration << " μs" << endl;
}