#include <bits/stdc++.h>
using namespace std;


void patSearch(char text[], char pattern[])
{
    int i=0, j=0;
    while(text[i] != '\0')
    {
        if(pattern[j] == '\0')
        {
            cout << "Pattern found at index" << i - j << endl;
            j = 0;
        }
        if(text[i++] == pattern[j++])
        {
            continue;
        }
        else
        {
            j=0;
        }
    }
}

int main()
{
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";
    patSearch(text, pattern);

    return 0;
}
