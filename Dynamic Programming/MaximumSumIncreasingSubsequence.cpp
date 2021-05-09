#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int LIS(int prev, int curr, int arr[], int len)
{
    if(curr == len-1)
        return 0;
    if(prev != -1 && dp[prev][curr] != -1)
        return dp[prev][curr];

    int op1 = 0;
    if(prev == -1 || arr[prev] < arr[curr])
        op1 = arr[curr] + LIS(curr, curr+1, arr, len);

    int op2 = LIS(prev, curr+1, arr, len);

    if(prev != -1)
        dp[prev][curr] = max(op1, op2);
    return max(op1, op2);
}

int main()
{
    int arr[] = {1, 2, 7, 3, 6, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
    cout << "The length of Longest increasing subsequence is : " << LIS(-1, 0, arr, len);
    return 0;
}
