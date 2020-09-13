#include <stdio.h>
//This code is for selection Sort. I am inputing the array from the user and then sorting the array and then printing it back.

void selectionSort(int *a, int len)
{
    int min;
    int minindex;
    int temp;
    for(int i=0; i<len; i++)
    {
        min = a[i];
        minindex = i;
        for(int j=(i+1); j<len; j++)
        {
            if(min>a[j])
            {
                min = a[j];
                minindex = j;
            }
        }
        temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
    }
}

void printArray(int *a, int len)
{
    for(int i=0; i<len; i++)
    {
       printf("%d", a[i]);
    }
}

int main()
{
    int n;
    printf("Select the number of elements in the array:");
    scanf("%d", &n);

    int array[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }

    selectionSort(array, n);

    printArray(array, n);

return 0;
}
