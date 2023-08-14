#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int ninjaAndLadoos(vector<int> &nums1, vector<int> &nums2, int m, int n, int k) {
    // Write your code here.
    if (m > n) return ninjaAndLadoos(nums2, nums1, n, m, k);

    int low = max(0, k - n), high = min(k, m);
    int left = k;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < m)
            r1 = nums1[mid1];
        if (mid2 < n)
            r2 = nums2[mid2];
        if (mid1 > 0)
            l1 = nums1[mid1 - 1];
        if (mid2 > 0)
            l2 = nums2[mid2 - 1];

        if (l1 > r2)
            high = mid1 - 1;
        else if (l2 > r1)
            low = mid1 + 1;
        else return max(l1, l2);
    }

    return 0;
}

int main()
{
    
    return 0;
}