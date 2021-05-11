#include<bits/stdc++.h>
#define R 6
#define C 5
using namespace std;

void printMaxSubSquare(int M[R][C])
{
    int s[R][C];
    for(int i=0; i<C; i++)
        s[R-1][i] = M[R-1][i];
    for(int i=0; i<R; i++)
        s[i][C-1] = M[i][C-1];

    for(int i=R-2; i>=0; i--)
    {
        for(int j=C-2; j>=0; j--)
        {
            if(M[i][j] == 0)
                s[i][j] = 0;
            else
            {
                s[i][j] = 1 + min(s[i][j+1], min(s[i+1][j], s[i+1][j+1]));
            }
        }
    }

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
        int M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);
    return 0;
}
