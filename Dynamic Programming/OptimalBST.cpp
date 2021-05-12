#include<bits/stdc++.h>
using namespace std;

int main()
{
    int keys[] = {10, 12, 15, 20};
    int freq[] = {4, 8, 5, 9};
    int n = sizeof(keys)/sizeof(keys[0]);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int gap=0; gap<n; gap++)
    {
        for(int i=0; i<n-gap; i++)
        {
            int j = gap+i;
            if(gap ==0)
            {
                dp[i][j] = freq[i];
            }
            else if(gap == 1)
            {
                dp[i][j] = min((freq[i]+2*freq[j]), freq[j]+2*freq[i]);
            }
            else
            {
                int sum = 0;
                int minimum = INT_MAX;
                for(int k=i; k<=j; k++)
                {
                    sum += freq[k];
                }
                for(int k=i; k<=j; k++)
                {
                    int left = dp[i][k-1];
                    int right = dp[k+1][j];
                    if(left+right+sum < minimum)
                        minimum = left+right+sum;
                }
                dp[i][j] = minimum;
            }
        }

    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
