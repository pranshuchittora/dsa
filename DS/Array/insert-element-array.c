//Program to insert an element at a given position in an array
/*
=========================================
Developer       :       Pranshu Chittora
Date            :       2018-09-22
=========================================
*/
#include <stdio.h>

void insertElm(int *arr, int n, int pos, int val)
{
    int i;
    for(i=n-1;i>=pos;i--)
    {
        *(arr+i+1)=*(arr+i);
    }
    *(arr+pos)=val;
    n++;
}
void displayArr(int *arr,int n)
{
    int i;
    printf("Elements of array : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
     printf("\n");   
}

int main()
{
    int n;
    
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n + 1];

    int i;
    printf("Enter the element of array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int pos, val;
    printf("Enter the position of new element : ");
    scanf("%d", &pos);
    printf("Enter the value of the new element : ");
    scanf("%d", &val);

    displayArr(arr,n);

    insertElm(arr, n, pos, val);
    //After insertion the size increases by 1
    n++;

    displayArr(arr,n);
    return 0;
}