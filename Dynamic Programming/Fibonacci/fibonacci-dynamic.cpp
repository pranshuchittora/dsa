#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const unsigned long long total = 45;
unsigned long long arr[total] = {0};

unsigned long long fib(int n)
{

    if (n <= 1)
        return 1;

    else
    {
        if (arr[n - 1] && arr[n - 2])
            return arr[n - 1] + arr[n - 2];
        else
            return fib(n - 1) + fib(n - 2);
    }
}

int main()
{

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (unsigned long long i = 1; i <= total; i++)
    {
        arr[i] = fib(i);
        cout << i << " => " << arr[i] << endl;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << endl
         << endl
         << "Execution Time -> " << (double)duration / 1000000 << " sec"
         << " | " << (double)duration / 1000 << " ms"
         << " | " << (double)duration << " μs" << endl;
}