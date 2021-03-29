#include<bits/stdc++.h>
using namespace std;


void arrange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[6] = {3, 5, 1, 4, 9, 7};
    int c = 6;
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<(c-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                arrange(&arr[j], &arr[j+1]);
            }
        }
    }
    for(int i=0; i<c; i++)
    {
        cout << arr[i] << "  ";
    }
}
