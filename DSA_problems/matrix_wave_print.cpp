#include <bits/stdc++.h>
using namespace std;

void wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    for(int i= 0; i<mCols; i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j<nRows; j++)
            {
                cout<<(arr[j][i])<<' ';
            }
            cout<<endl;
        }
        else
        {
            for(int j=nRows-1; j>=0; j--)
            {
                cout<<(arr[j][i])<<' ';
            }
            cout<<endl;
        }    
    }
}

int main()
{
    vector<vector<int>> v = {{3,4,5,6},{4,3,2,4},{5,4,4,3}};
    wavePrint(v, 3, 4);
    return 0;
}