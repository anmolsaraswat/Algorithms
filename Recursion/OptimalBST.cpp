#include<bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j)
{
    int s=0;
    for(int k=i; k<=j; k++)
        s+=freq[k];
    return s;
}

int optimalBST(int freq[], int i, int j)
{
    if (i>j)
        return 0;
    if(i==j)
        return freq[i];
    int fsum = sum(freq, i, j);

    int minimum = INT_MAX;

    for(int r=i; r<=j; ++r)
    {
        int cost = optimalBST(freq, i, r-1) + optimalBST(freq, r+1, j);
        if(cost < minimum)
            minimum = cost;
    }

    return (minimum+fsum);
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout << "Cost of Optimal BST is : " << optimalBST(freq, 0, n-1);

    return 0;
}
