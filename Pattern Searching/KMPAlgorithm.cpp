#include<bits/stdc++.h>
using namespace std;


int main()
{
    char text[] = "AAABADACAADAABAAABAA";
    char pattern[] = "AABA";
    int tlen = sizeof(text)/sizeof(text[0]);
    int plen = sizeof(pattern)/sizeof(pattern[0]) - 1;

    int lps[plen];
    lps[0] = 0;

    int i=0, j=1;
    while( j<plen){
        if(pattern[i] == pattern[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else if( i ==0 ){
            lps[j++] = 0;
        }
        else{
            i = lps[i-1];
        }
    }


    i=0, j=0;
    while(i<tlen){
        if(pattern[j] == '\0'){
            cout << "Found the pattern at index : " << i-j << endl;
            j=0;
        }
        if(text[i] == pattern[j]){
                j++;
                i++;
        }
        else if(j !=0){
            j = lps[j-1];
        }
        else{
            i++;
        }
    }
}
