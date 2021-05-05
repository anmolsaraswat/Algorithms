#include<bits/stdc++.h>
using namespace std;


int change(int ind, int sum, int S[], int n)
{
    if(sum == 0)
        return 1;
    if(ind>=n || sum < 0)
        return 0;
    int left = change(ind, sum-S[ind], S, n);
    int right = change(ind+1, sum, S, n);
    return left + right;
}

int main()
{
    int S[] = {1,2,3,4};
    int sum = 5;
    int n = 4;
    cout << change(0, sum, S, n);
    return 0;
}
