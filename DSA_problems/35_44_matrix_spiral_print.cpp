#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector <int>v;
    int startingrow = 0;
    int endingrow = row-1;
    int startingcol = 0;
    int endingcol = col-1;

    int total = row*col;
    int count = 0;

    while(count <total)
    {
        for (int i = startingcol; count < total && i <= endingcol; i++)
        {
            v.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;

        for (int i = startingrow; count < total && i <= endingrow; i++)
        {
            v.push_back(matrix[i][endingcol]);
            count++;
        }
        endingcol--;

        for (int i = endingcol; count < total && i >= startingcol; i--)
        {
            v.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;
        
        for (int i = endingrow; count < total && i >= startingrow; i--)
        {
            v.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    return v;
} 

int main()
{
    vector<vector<int>> v;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>v[i][j];
        }
    }

    vector<int> ans = spiralOrder(v);
    
    return 0;
}