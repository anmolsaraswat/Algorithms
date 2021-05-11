#include<bits/stdc++.h>
using namespace std;

int countSS(string str, int n)
{
    int result = 0;
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i] = true;
    for(int i=0; i<n-1; i++)
    {
        if(str[i] == str[i+1])
            dp[i][i+1] = true;
    }

    for(int diff = 2; diff<n; diff++)
    {
        for(int i = 0; i<n-diff; i++)
        {
            int j = diff + i;
            if(str[i] == str[j])
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dp[i][j])
                result++;
        }
    }
    return result;
}

int main()
{
    string str = "abccbc";
    int n = str.size();
    cout << countSS(str, n);

    return 0;
}
