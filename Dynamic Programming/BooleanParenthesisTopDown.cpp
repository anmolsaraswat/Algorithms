#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "TFTF";
    string s2 = "&|^";
    int len = s1.size();
    int dpt[len][len];
    int dpf[len][len];
    memset(dpt, 0, sizeof(dpt));
    memset(dpf, 0, sizeof(dpf));
    for(int g=0; g<len; g++)
    {
        for(int i=0; i<len-g; i++)
        {
            int j = i+g;
            if(g == 0)
            {
                if(s1[i] == 'T')
                {
                    dpt[i][j] = 1;
                    dpf[i][j] = 0;
                }
                else
                {
                    dpt[i][j] = 0;
                    dpf[i][j] = 1;
                }
            }
            else
            {
                for(int k = i; k<j; k++)
                {
                    int ltc = dpt[i][k];
                    int rtc = dpt[k+1][j];
                    int lfc = dpf[i][k];
                    int rfc = dpf[k+1][j];

                    if(s2[k] == '&')
                    {
                        dpt[i][j] += ltc*rtc;
                        dpf[i][j] += (ltc*rfc) + (lfc*rtc) + (lfc*rfc);
                    }
                    else if(s2[k] == '|')
                    {
                        dpt[i][j] += (ltc*rtc) + (lfc*rtc) + (ltc*rfc);
                        dpf[i][j] += (lfc*rfc);
                    }
                    else
                    {
                        dpt[i][j] += (ltc*rfc) + (lfc*rtc);
                        dpf[i][j] += (ltc*rtc) + (lfc*rfc);
                    }
                }

            }
        }
    }
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            cout << dpt[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
