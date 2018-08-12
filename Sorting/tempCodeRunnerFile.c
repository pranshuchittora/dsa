#include <stdio.h>
void Insertion_Sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[8] = {5, 1, 4, 2, 8, 3, 7, 6};
    int n = 8;

    printf("Unsorted Array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    Insertion_Sort(arr, n);

    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}