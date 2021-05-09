#include<bits/stdc++.h>
using namespace std;


int LIS(int prev, int curr, int arr[], int len)
{
    if(curr == len-1)
        return 0;

    int op1 = 0;
    if(prev == -1 || arr[prev] < arr[curr])
        op1 = arr[curr] + LIS(curr, curr+1, arr, len);

    int op2 = LIS(prev, curr+1, arr, len);
    return max(op1, op2);
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "The length of Longest Sum increasing subsequence is : " << LIS(-1, 0, arr, len);
    return 0;
}
