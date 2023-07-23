#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_map<int, bool> row, col;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!matrix[i][j])
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (auto it : row)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[it.first][j] = 0;
        }
    }

    for (auto it : col)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][it.first] = 0;
        }
    }
}

int main()
{

    return 0;
}