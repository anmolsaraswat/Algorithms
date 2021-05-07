#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int isSubsetSum(int arr[], int n, int sum)
{
    if(sum == 0)
        return 1;
    if(n <= 0)
        return 0;
    if(dp[n-1][sum] != -1)
        return dp[n-1][sum];
    if(arr[n-1] > sum)
        return dp[n-1][sum] = isSubsetSum(arr, n-1, sum);

    return dp[n-1][sum] = isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}


int main()
{
    int arr[] = { 2, 34, 4, 12, 5, 2};
    int sum = 9;
    memset(dp, -1, sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isSubsetSum(arr, n, sum))
        cout << "Found a subset with a given sum";
    else
        cout << "No subset with given sum";

    return 0;
}
