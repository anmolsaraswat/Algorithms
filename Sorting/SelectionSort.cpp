#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {24, 66, 198, 90, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        int index=0;
        int temp =0;
        for(int j=i; j<n; j++)
        {
            if(arr[i]<arr[j])
                index = i;
            else
                index = j;
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] << "  ";
    }
}
