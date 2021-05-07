#include<iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(arr[n-1] > sum)
        return isSubsetSum(arr, n-1, sum);

    return isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}


int main()
{
    int arr[] = { 2, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isSubsetSum(arr, n, sum) == true)
        cout << "Found a subset with a given sum";
    else
        cout << "No subset with given sum";

    return 0;
}
