#include<bits/stdc++.h>
using namespace std;

int dp[3][11];

int eggDrop(int e, int f)
{
    if(f ==0 || f == 1)
        return f;
    if( e == 1)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];


    int mn = INT_MAX;
    for(int k =1; k<=f; k++)
    {
        int temp = 1+ max(eggDrop(e-1, k-1), eggDrop(e, f-k));
        mn = min(mn, temp);
    }
    return dp[e][f] = mn;
}

int main()
{
    int n = 2, k=10;
    memset(dp, -1, sizeof(dp));

    cout << "Minimum Number of Trials in worst case : " << eggDrop(n,k) << endl;
    return 0;
}
