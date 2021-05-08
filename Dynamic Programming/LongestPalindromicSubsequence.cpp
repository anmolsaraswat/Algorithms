#include<bits/stdc++.h>
using namespace std;

int arr[1000][1000];


int lcs (char *X, char *Y, int m, int n)
{
    if(X[m] == '\0' || Y[n] == '\0')
        return 0;
    if(arr[m][n] != -1)
        return arr[m][n];
    if(X[m] == Y[n])
    {
        arr[m][n] = 1 + lcs(X, Y, m+1, n+1);
        return arr[m][n];
    }
    else
    {
        arr[m][n] = max(lcs(X, Y, m, n+1), lcs(X, Y, m+1, n));
        return arr[m][n];
    }

}

int main()
{
    memset(arr, -1, sizeof(arr));
    char X[] = "GEEKSFORGEEKS";
    char Y[] = "SKEEGROFSKEEG";
    cout<< "Length of LPS is " << lcs(X, Y, 0, 0);

    return 0;
}
