/*
============================
Developer : Pranshu Chittora
============================
START
Bubble_Sort ( ARR[] , N)
    Step 1 : Repeat Step 2 For i = 0 to N-1
    Step 2 :    Repeat For J = 0 to N-1
    Step 3 :        IF ARR[J] > ARR[J+1]
                    SWAP ARR[J] and ARR[J+1]
                [END OF INNER LOOP]
            [END OF OUTER LOOP]
    Step 4 : EXIT 
END
*/

#include <stdio.h>

void Bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[8] = {5, 1, 4, 2, 8, 3, 7, 6};
    int n = 8;
    printf("Unsorted Array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    Bubble_Sort(arr, n);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}