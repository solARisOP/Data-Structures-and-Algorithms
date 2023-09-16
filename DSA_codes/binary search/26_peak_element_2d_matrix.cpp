#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int max_ele(int &m, vvi &mat, int col)
{
    int maxi = -1;
    int row = 0;
    for (int i = 0; i < m; i++)
    {
        if (maxi < mat[i][col])
        {
            row = i;
            maxi = mat[i][col];
        }
    }
    return row;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int rows = mat.size(), cols = mat[0].size();
    int low = 0, high = cols;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int i = max_ele(rows, mat, mid);

        int left = mid - 1 == -1 ? -1 : mat[i][mid - 1];
        int right = mid + 1 == cols ? -1 : mat[i][mid + 1];

        if (mat[i][mid] > left && mat[i][mid] > right)
            return {i, mid};

        if (left > mat[i][mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return {-1, -1};
}

int main()
{

    return 0;
}