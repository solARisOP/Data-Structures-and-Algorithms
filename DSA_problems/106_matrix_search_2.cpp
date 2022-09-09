#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();

    int r = 0, c = col - 1;
    while (c >= 0 && r < row)
    {
        int element = matrix[r][c];
        if (element == target)
        {
            return 1;
        }

        else if (element > target)
        {
            c--;
        }

        else
        {
            r++;
        }
    }
    return 0;
}

int main()
{

    return 0;
}