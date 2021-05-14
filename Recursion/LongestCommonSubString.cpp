#include<bits/stdc++.h>
using namespace std;


int lcs ( char *X, char *Y, int m, int n, int res)
{
    if(X[m] == '\0' || Y[n] == '\0')
        return res;
    if(X[m] == Y[n])
        return res = lcs(X, Y, m+1, n+1, res+1);
    else
        return max(res, max(lcs(X, Y, m, n+1, 0), lcs(X, Y, m+1, n, 0)));

}

int main()
{
    char X[] = "GEEKS";
    char Y[] = "HELLO";


    cout << "Length of LCS is " << lcs(X, Y, 0, 0, 0);
    return 0;
}
