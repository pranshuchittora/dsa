/*
START
Linear_Search (ARR[] , N , K)
    Step 1 : Int Pos = -1
    Step 2 : Int i = 0
        Repeat Step 3 for n times
            Step 3 : If ARR[i] == k
                Step 3.1 : pos = i + 1
                Step 3.2 : Print pos
                Go to Step 5 
            [END OF IF]
        [END OF LOOP]
    Step 4 : If pos == -1
        print "Element not found"
    [END OF IF]    
    Step 5 : EXIT 
END
*/

#include <stdio.h>

void Linear_Search(int arr[], int n, int k)
{

    int pos = -1;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            pos = i + 1;
            printf("ELEMENT FOUND AT -> %d", pos);
            break;
        }
    }
    if (pos == -1)
        printf("ELEMENT NOT FOUND");
}

int main()
{

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8, k = 15;

    Linear_Search(arr, n, k);

    return 0;
}