/*
============================
Developer : Pranshu Chittora
============================
START
Insertion_Sort ( ARR[] , N)
    Step 1 : Repeat Step 2 to 5 For K = 0 to N-1
    Step 2 :    Set TEMP = ARR[K]
    Step 3 :    Set J = K - 1
    Step 4 :    Repeat While TEMP <= ARR[J]
                    Set ARR[J+1] = ARR[J]
                    Set J = J - 1
                [END OF INNER LOOP]
    Step 5 :    Set ARR[J+1] = TEMP
            [END OF LOOP]                
    Step 6 : EXIT        
END
_____________________

Complexity
O(n*(n-1)/2)
_____________________
*/

#include <stdio.h>
void Insertion_Sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
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