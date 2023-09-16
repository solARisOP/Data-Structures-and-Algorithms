#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int ele_count(vvi &mat, int x)
{
    int m = mat.size();
    int n = mat[0].size();

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
    }

    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n)
{
    // Write your code here.
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int threshold = (m * n) / 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int cnt = ele_count(matrix, mid);
        if (cnt > threshold)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{

    return 0;
}