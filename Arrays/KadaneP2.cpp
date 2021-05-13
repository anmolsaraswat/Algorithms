#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, -3, -2, 6, 7, -10, -10, 5, 5, 9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int obest=0, cbest=0;
    for(int i=0; i<len; i++)
    {
        if(cbest + arr[i] > 0)
            cbest += arr[i];
        else
            cbest = 0;
        if(cbest > obest)
            obest = cbest;
    }
    cout << "Maximum sum of subarray : " << obest;
}
