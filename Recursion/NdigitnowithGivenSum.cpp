#include<bits/stdc++.h>
using namespace std;


int countRec(int n, int sum)
{
    if(n==0)
        return sum==0;
    if(sum == 0)
        return 1;

    int ans=0;
    for(int i=0; i<=9; i++)
        if(sum-i >= 0)
            ans += countRec(n-1, sum-i);

    return ans;

}

int finalCount(int n, int sum)
{
    int ans = 0;

    for(int i=1; i<=9; i++)
        if(sum-i >= 0)
            ans += countRec(n-1, sum-i);

    return ans;
}

int main()
{
    int n=2, sum =5;
    cout << finalCount(n, sum);
    return 0;
}
