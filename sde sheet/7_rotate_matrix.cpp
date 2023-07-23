#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = 0; j < col; j++)
        {
            swap(matrix[i][j], matrix[row - i - 1][j]);
        }
    }

    int i = 0, j = 0;
    while (i < row)
    {
        while (j < col)
        {
            swap(matrix[i][j], matrix[j][i]);
            j++;
        }
        i++;
        j = i;
    }
}

int main()
{

    return 0;
}