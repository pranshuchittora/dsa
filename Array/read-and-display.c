//Program to read and display elements of an array
/*
=========================================
Developer       :       Pranshu Chittora
Date            :       2018-09-22
=========================================
*/
#include <stdio.h>

int main()
{
    int n;
    //Taking input of the array size
    printf("Enter the size of array : ");
    scanf("%d", &n);

    // Declaring array dynamically
    int arr[n];

    //Taking user input
    int i;
    printf("Enter the elements of the array \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    //Displaying the elements of the array
    printf("\nElements of array are : ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);

}