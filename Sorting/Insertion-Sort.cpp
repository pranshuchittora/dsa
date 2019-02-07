#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    cout << "-- INSERTION SORT --" << endl;

    int n = 8;
    int arr[n] = {7, 4, 5, 3, 2, 8, 1, 6};

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            arr[j] = key;
            j--;
        }
        display(arr, n);
    }

    return 0;
}