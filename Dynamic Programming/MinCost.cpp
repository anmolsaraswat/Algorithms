#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int minCost(int cost[R][C], int m, int n, vector<vector<int>> &dp)
{
    if(m>=R || n>=C)
        return INT_MAX;
    else if(m==(R-1) && n==(C-1))
        return cost[m][n];
    else if(dp[m][n] != -1)
        return dp[m][n];
    else
        return dp[m][n] = (cost[m][n] + min(minCost(cost, m+1, n, dp), minCost(cost, m, n+1, dp)));
}

int main()
{
    int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3} };
    vector<vector<int>>dp(R,vector<int>(C, -1));
    cout << minCost(cost, 0, 0, dp);

    return 0;
}
