#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i=0; i<len; i++)
    {
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_so_far < 0)
            max_ending_here = 0;
    }
    cout << "Greatest Contiguous Subarray : " << max_so_far;
}
