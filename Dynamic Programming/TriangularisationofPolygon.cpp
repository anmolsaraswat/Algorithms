#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[] = {2, 1, 4, 6, 2, 1};
    int len = 6;
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for(int gap=0; gap<len; gap++)
    {
        for(int i=0; i<len-gap; i++)
        {
            int j=i+gap;
            if(gap == 0 || gap == 1)
                dp[i][j] = 0;
            else if(gap ==2)
            {
                dp[i][j] = arr[i] * arr[j] * arr[i+1];
            }
            else
            {
                int minimum = INT_MAX;
                for(int k=i+1; k<j; k++)
                {
                    int cost = arr[i]*arr[j]*arr[k];
                    int left = dp[i][k];
                    int right = dp[k][j];
                    int total = cost + left + right;
                    if(total<minimum)
                        minimum = total;
                }
                dp[i][j] = minimum;
            }
        }
    }

    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
