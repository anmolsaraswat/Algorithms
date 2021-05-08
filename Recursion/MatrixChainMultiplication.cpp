#include<bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int minimum = INT_MAX;
    int temp;

    for(k = i; k<j; k++)
    {
        temp = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k+1, j) + p[i-1] * p[k] * p[j];
        if(temp < minimum)
            minimum = temp;
    }

    return minimum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Minimum number of Multiplication is : " << MatrixChainOrder(arr, 1, n-1);

    return 0;
}
