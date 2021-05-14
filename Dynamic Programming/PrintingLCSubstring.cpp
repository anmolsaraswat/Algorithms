#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a = "GHEACD";
    string b = "MEACLN";
    string ans = "";
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];
    int maximum = INT_MIN;
    int index = -1;
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > maximum){
                            maximum = dp[i][j];
                            index = j-1;
                    }
            }
            else
                dp[i][j] = 0;
        }
    }
    for(int i=index; i>=index-maximum+1; i--)
    {
        ans.push_back(b[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
