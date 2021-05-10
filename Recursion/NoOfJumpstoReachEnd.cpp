#include<bits/stdc++.h>
using namespace std;


int reachEnd(int arr[], int len, int curr)
{
    if(curr == len-1)
        return 0;
    int minimum = INT_MAX;
    int maxJump = arr[curr];
    while(maxJump > 0)
    {
        minimum = min(minimum, 1+ reachEnd(arr, len, curr+maxJump));
        maxJump--;
    }
    return minimum;
}

int main()
{
    int arr[] = {2, 3, 1, 1, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << " Minimum number of jumps required to reach end : " << reachEnd(arr, len, 0);

    return 0;
}
