//Printing all the subsets of a array using bitmasking

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int array[3] = {1, 2, 3};
    int arraylen = sizeof(array)/sizeof(array[0]);
    int noOfSubsets = pow(2, arraylen);
    cout<< noOfSubsets;

    for (int i=0; i< arraylen; i++)
    {
        cout<< array[i];
    }

    for(int counter=0; counter<noOfSubsets; counter++)
    {
        for(int i=0; i<arraylen; i++)
        {
            if( (counter >>(i))& 1)
            {
                cout<< array[i];
            }
        }
        cout << endl;
    }
}
