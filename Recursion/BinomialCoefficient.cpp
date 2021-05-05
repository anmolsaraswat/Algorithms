#include<bits/stdc++.h>
using namespace std;


int nCr(int n, int k)
{
    if(k==n || k == 0)
        return 1;
    else return nCr(n-1, k-1) + nCr(n-1,k);
}

int main()
{
    int n = 7;
    int k = 3;
    cout << nCr(n, k);
    return 0;
}
