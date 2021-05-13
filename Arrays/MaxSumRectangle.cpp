#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{
    int obest=0, cbest=0;
    for(int i=0; i<n; i++)
    {
        if(cbest + arr[i] > 0)
            cbest += arr[i];
        else
            cbest = 0;
        if(cbest > obest)
            obest = cbest;
    }
    return obest;
}

int sum(int arr[][5], int dp[], int a, int b)
{
    int maximumSum = INT_MIN;
    for(int i=0; i<a; i++)
    {
        for(int k=0; k<b; k++)
        {
            dp[k] = arr[i][k];
        }
        int temp = kadane(dp, b);
        if(temp > maximumSum)
            maximumSum = temp;
        for(int j=i+1; j<a; j++)
        {
            for(int k=0; k<b; k++)
                dp[k] +=arr[j][k];

            temp = kadane(dp, b);

            if(temp>maximumSum)
                maximumSum = temp;
        }
    }
    return maximumSum;
}

int main()
{
    int arr[4][5] = { {1, 2, -1, -4, -20},
                      {-8, -3, 4, 2, 1 },
                      {3, 8, 10, 1, 3},
                      {-4, -1, 1, 7, -6}};
    int dp[5] = {0, 0, 0, 0, 0};
    cout << "Sum of Maximum sub rectangle in 2-D array is : " << sum(arr, dp, 4, 5);
    return 0;
}
