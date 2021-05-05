#include<bits/stdc++.h>
using namespace std;


int change(int ind, int sum, int S[], int n, vector<vector<int>> &dp)
{
    if(sum == 0)
        return 1;
    if(ind>=n || sum < 0)
        return 0;
    if(dp[ind][sum] != -1)
        return dp[ind][sum];
    int left = change(ind, sum-S[ind], S, n, dp);
    int right = change(ind+1, sum, S, n, dp);
    return dp[ind][sum] = left + right;
}

int main()
{
    int S[] = {1,2,3,4};
    int sum = 5;
    int n = 4;
    vector<vector<int>>dp(n, vector<int>(sum+1, -1));
    cout << change(0, sum, S, n,dp);
    return 0;
}
