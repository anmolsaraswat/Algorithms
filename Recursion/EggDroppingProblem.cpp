#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f)
{
    if(f ==0 || f == 1)
        return f;
    if( e == 1)
        return f;

    int mn = INT_MAX;
    for(int k =1; k<=f; k++)
    {
        int temp = 1+ max(eggDrop(e-1, k-1), eggDrop(e, f-k));
        mn = min(mn, temp);
    }
    return mn;
}

int main()
{
    int n = 2, k=10;

    cout << "Minimum Number of Trials in worst case : " << eggDrop(n,k) << endl;
    return 0;
}
