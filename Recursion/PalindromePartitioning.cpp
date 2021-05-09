#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false;
      i++;
      j--;
    }
    return true;
}


int PPartition(string String, int i, int j)
{
    if(i>=j || isPalindrome(String, i, j))
        return 0;
    int ans = INT_MAX, c;
    for(int k=i; k<j; k++)
    {
        c = PPartition(String, i, k) + PPartition(String, k+1, j) + 1;
        ans = min(ans, c);
    }
    return ans;
}



int main()
{
    string str = "ababbbabbababa";
    cout << "Minimum cuts needed for Palindrome Partitioning is : " << PPartition(str, 0, str.length()-1) << endl;

    return 0;
}
