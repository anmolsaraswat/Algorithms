#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& v)
{
    for(int i=0; i<v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void printSubsetsRec(int arr[], int i, int sum, vector<int> p, int dp[][11])
{
    if(sum == 0)
    {
        display(p);
        return;
    }
    if(dp[i-1][sum])
    {
        vector<int> b = p;
        printSubsetsRec(arr, i-1, sum, b, dp);
    }
    if(sum >= arr[i-1] && dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i-1]);
        printSubsetsRec(arr, i-1, sum-arr[i-1], p, dp);
    }
}



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
    {
        cout << "We have the following subsets : " << endl;
        vector<int> p;
        printSubsetsRec(arr, 5, sum, p, dp);
    }
    else
        cout << "We don't have a subset with a given sum";

}
