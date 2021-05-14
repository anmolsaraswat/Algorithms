#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 9;
    int dp[10];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<10; i++)
    {
        for(int j=0; j<i; j++)
        {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << dp[i] << " ";
    }
}
