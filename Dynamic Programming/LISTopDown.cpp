#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int lis[len];
    lis[0] = 1;

    for(int i=1; i<len; i++)
    {
        int temp = INT_MIN;
        for(int j=0; j<i; j++)
        {
            if(arr[j] < arr[i] && temp < lis[j])
            {
                temp = lis[j];
            }
        }
        if(temp == INT_MIN)
            lis[i] = 1;
        else
            lis[i] = 1+temp;
    }
    for(int i=0; i<len; i++)
        cout << lis[i] << " ";
}
