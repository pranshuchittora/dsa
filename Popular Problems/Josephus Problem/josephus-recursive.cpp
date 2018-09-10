#include <iostream>
using namespace std;

int survivorPosition(int n, int k)
{
    if (n == 1)
        return 1;
    return (survivorPosition(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n, k;

    cout << "Enter the total number of soldiers : ";
    cin >> n;
    cout << "Enter the number of persons to be skipped at each execution : ";
    cin >> k;

    int ans = survivorPosition(n, k);
    cout << endl
         << "Survivor's Position = " << ans << endl;

    return 0;
}