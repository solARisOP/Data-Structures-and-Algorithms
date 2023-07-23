#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int r = mid / cols;
        int c = mid % cols;

        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{

    return 0;
}