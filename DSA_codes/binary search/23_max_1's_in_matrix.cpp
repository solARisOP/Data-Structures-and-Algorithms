#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// O(n*logm)
int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int maxi =0, ind = -1;
    for(int i=0; i<n; i++)
    {
        int l = lowerBound(matrix[i], n, 1);
        if(m-l > maxi)
        {
            maxi = m-l;
            ind = i;
        }
    }
    return ind;
}

// O(n+m)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int ind=-1;
    int idx = -1;
    for(int i=m-1; i>=0; i--)
    {
        if (!matrix[0][i]) {
            ind = i;
            if(i+1<m)idx=0;
            break;
        }
    }
    if(ind == -1) return 0;
    for(int i=1; i<n; i++)
    {
        if(matrix[i][ind])
        {
            while(ind>=0 && matrix[i][ind]) ind--;
            if(ind == -1) return i;
            else idx = i;
        }
    }

    return idx;    
}

int main()
{
    
    return 0;
}