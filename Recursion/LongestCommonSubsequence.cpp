#include<bits/stdc++.h>
using namespace std;


int lcs ( char *X, char *Y, int m, int n)
{
    if(X[m] == '\0' || Y[n] == '\0')
        return 0;
    if(X[m] == Y[n])
        return 1+lcs(X, Y, m+1, n+1);
    else
        return max(lcs(X, Y, m, n+1), lcs(X, Y, m+1, n));

}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";


    cout << "Length of LCS is " << lcs(X, Y, 0, 0);
    return 0;
}
