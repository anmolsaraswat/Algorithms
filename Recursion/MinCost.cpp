#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int minCost(int cost[R][C], int m, int n)
{
    if(m>R-1 || n>C-1)
        return INT_MAX;
    else if(m==(R-1) && n==(C-1))
        return cost[m][n];
    else
        return cost[m][n] + min(minCost(cost, m+1, n), minCost(cost, m, n+1));
}

int main()
{
    int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3} };

    cout << minCost(cost, 0, 0);

    return 0;
}
