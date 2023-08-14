#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// O(m) + O(log n)
bool binary_Search(vi a, int k)
{
    int n = a.size();
    int low=0, high = n-1;

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(a[mid] == k) return 1;
        else if(a[mid]>k) high = mid - 1;
        else low = mid + 1;
    }

    return 0;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    for(int i=0; i<m; i++)
    {
        if(mat[i][0] <= target && target <= mat[i][n-1]) return binary_Search(mat[i], target);
    }

    return false;
}

// O(log(m*n))
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();
    int low =0, high = m*n-1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int r = mid/n, c = mid%n;

        if(mat[r][c] == target) return 1;
        else if(mat[r][c] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main()
{
    
    return 0;
}