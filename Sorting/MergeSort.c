#include<stdio.h>

void printArray(int *a, int no_of_ele)
{
    for(int i=0; i<no_of_ele; i++)
    {
        printf("%d ", a[i]);
    }
}
mergeSort(int Arr[], int left, int right)
{
    if(left < right)
    {
        int middle= left + (right - left)/2;
        mergeSort(Arr, left, middle);
        mergeSort(Arr, middle+left, right);
        merge()
    }
}


int main()
{
    int no_of_ele;
    printf("No of elements: ");
    scanf("%d", &no_of_ele);
    int Arr[no_of_ele];
    for(int i=0; i<no_of_ele; i++)
    {
        scanf("%d", &Arr[i]);
    }
    mergeSort(Arr, 0, no_of_ele-1);
    printArray(Arr, no_of_ele);
    return 0;
}
