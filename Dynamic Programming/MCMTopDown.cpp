#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int dp[len-1][len-1];
    memset(dp, 0, sizeof(dp));

    for(int gap=0; gap<len-1; gap++)
    {
        for(int i=0; i<len-1-gap; i++)
        {
            int j = i+gap;
            //cout << i << " " << j<< endl;
            if(gap == 0)
                dp[i][j] = 0;
            else if(gap == 1)
            {
                dp[i][j] = arr[i]*arr[i+1]*arr[j+1];
            }
            else
            {
                int m = INT_MAX;
                for(int k=i; k<j; k++)
                {
                    int lc = dp[i][k];
                    int rc = dp[k+1][j];
                    int mc = arr[i]*arr[k+1]*arr[j+1];
                    //cout << lc << " " << rc << " " << mc << endl;
                    int tc = lc+rc+mc;
                    if(tc<m)
                        m = tc;
                }
                //cout << "Minimum : " << m << endl;
               dp[i][j] = m;
            }
        }
    }
    for(int i=0; i<len-1; i++)
    {
        for(int j = 0; j<len-1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
