#include<bits/stdc++.h>
using namespace std;

void countSS(string str, int n)
{
    int maxdifference, x, y;
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
                maxdifference = diff;
                x=i-1;
                y=j;
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    cout << maxdifference+1 << endl;
    for(int i=x; i<y; i++)
    {
        cout << str[i];
    }
}

int main()
{
    string str = "abccbc";
    int n = str.size();
    countSS(str, n);

    return 0;
}
