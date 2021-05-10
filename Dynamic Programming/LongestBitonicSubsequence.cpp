#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int lis[len];
    int lds[len];
    int bts[len];
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


    lds[len-1] = 1;
    for(int i=len-2; i>=0; i--)
    {
        int temp = INT_MIN;
        for(int j = i+1; j<len; j++)
        {
            if(arr[j] < arr[i] && temp < lds[j])
                temp = lds[j];
        }
        if(temp == INT_MIN)
            lds[i] = 1;
        else
            lds[i] = 1 + temp;


    }
    for(int i=0; i<len; i++)
    {
        bts[i] = lis[i] + lds[i] -1;
        cout << bts[i] << " ";
    }
}
