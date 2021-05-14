#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a = "abcf";
    string b = "abcdef";
    string s = "";
    int dp[a.size()+1][b.size()+1];

    memset(dp, -1, sizeof(dp));

    for(int i=0; i<=a.size(); i++)
        dp[i][0] = 0;
    for(int j=0; j<=b.size(); j++)
        dp[0][j] = 0;

    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int i = a.size(), j = b.size();

    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s;
}
