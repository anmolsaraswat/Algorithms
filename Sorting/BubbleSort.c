#include <stdio.h>


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *Arr, int no_of_ele)
{
    for(int i=0; i<no_of_ele; i++)
    {
        for(int j=i; j<no_of_ele; j++)
        {
            if(Arr[i]>Arr[j])
            {
                swap(&Arr[i], &Arr[j]);
            }
        }
    }
}
void printArray(int *a, int no_of_ele)
{
    for(int i=0; i<no_of_ele; i++)
    {
        printf("%d ", a[i]);
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
    BubbleSort(Arr, no_of_ele);
    printArray(Arr, no_of_ele);
    return 0;
}
