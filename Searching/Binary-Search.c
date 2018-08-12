/*
============================
Developer : Pranshu Chittora
============================
START
Binary_Search ( ARR[] , lower_bound , upper_bound , K)
    Step 1 : BEG = lower_bound
    Step 2 : END = upper_bound
    Step 3 : Pos = -1

        Repeat Step 4 & 5 while BEG <= END
            Step 4 : SET MID = (BEG + END)/2
            Step 5 : IF ARR[MID] == K
                    POS = MID + 1
                    Print POS
                    Go to Step 7

                    ELSE IF ARR[MID] > K
                        SET END = MID - 1
                    ELSE
                        SET BEG = MID + 1
                    [END OF IF]
        [END OF LOOP]        

    Step 6 : If pos == -1
        Print "Element not found"    
        [END OF IF]
    Step 7 : EXIT 
END
*/
#include <stdio.h>
void Binary_Search(int arr[], int lower_bound, int upper_bound, int k)
{
    int beg = lower_bound;
    int end = upper_bound;
    int pos = -1;
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (arr[mid] == k)
        {
            pos = mid + 1;
            printf("ELEMENT FOUND -> %d", pos);
            break;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else
            beg = mid + 1;
    }
    if (pos == -1)
        printf("ELEMENT NOT FOUND");
}

int main()
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8, k = 2;

    Binary_Search(arr, 0, n - 1, k);

    return 0;
}
