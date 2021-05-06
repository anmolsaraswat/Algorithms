#include<bits/stdc++.h>
using namespace std;
int dp[102][1002];

int knapsack(int W, int wt[], int val[], int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];
    if(wt[n-1] > W)
        return dp[n][W]=knapsack(W, wt, val, n-1);
    else
        return dp[n][W] = max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
}


int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);

    memset(dp, -1, sizeof(dp));
    cout << knapsack(W, wt, val, n);
    return 0;
}
