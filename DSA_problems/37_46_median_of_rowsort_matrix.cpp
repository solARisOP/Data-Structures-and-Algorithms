#include <bits/stdc++.h>
using namespace std;
void printmatrix(vector<vector<int>> arr, int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cout<<arr[r][c]<<'\t';
        }
        cout<<endl;
    }
}

int median(vector<vector<int>> &matrix, int r, int c)
{
    vector<int>v;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[v.size()/2];          
}

int main()
{
    vector<vector<int>> v = {{1,3,5}, {2,6,9}, {3,6,9}};
    swap(v[0][1], v[1][0]);
    // cout<<v[0][1];
    cout<<median(v, 3, 3);
    return 0;
}