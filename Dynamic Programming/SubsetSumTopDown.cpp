#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 2, 7, 1, 3};
    int sum = 10;

    int dp[6][11];
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<6; i++)
        dp[i][0] = 1;
    for(int i=1; i<11; i++)
        dp[0][i] = 0;
    for(int i=1; i<6; i++)
    {
        for(int j=1; j<11; j++)
        {
            if(j<arr[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        }
    }
    if(dp[6][11])
        cout << "We have a subset with a given sum";
    else
        cout << "We don't have a subset with a given sum";

}
