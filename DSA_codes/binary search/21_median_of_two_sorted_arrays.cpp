#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// O(N+M)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int ind1 = -1, ind2 = -1;
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == n / 2 - 1)
                ind1 = nums1[i];
            if (cnt == n / 2)
                ind2 = nums1[i];
            i++;
            cnt++;
        }
        else
        {
            if (cnt == n / 2 - 1)
                ind1 = nums2[j];
            if (cnt == n / 2)
                ind2 = nums2[j];
            j++;
            cnt++;
        }
    }
    while (i < n1)
    {
        if (cnt == n / 2 - 1)
            ind1 = nums1[i];
        if (cnt == n / 2)
            ind2 = nums1[i];
        i++;
        cnt++;
    }
    while (j < n2)
    {
        if (cnt == n / 2 - 1)
            ind1 = nums2[j];
        if (cnt == n / 2)
            ind2 = nums2[j];
        j++;
        cnt++;
    }

    if (n % 2)
        return double(ind2);
    else
        return double(double(ind1 + ind2) / 2.0);
}

// O(log(min(m,n)))
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int n = n1 + n2;
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 > 0)
            l1 = nums1[mid1 - 1];
        if (mid2 > 0)
            l2 = nums2[mid2 - 1];

        if (l1 > r2)
            high = mid1 - 1;
        else if (l2 > r1)
            low = mid1 + 1;
        else
        {
            if (n % 2)
                return (double)max(l1, l2);
            else
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
    }

    return 0;
}

int main()
{

    return 0;
}