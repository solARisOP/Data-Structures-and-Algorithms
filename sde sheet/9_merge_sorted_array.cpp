#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

//brute
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int j = 0, i = m; j < n; j++)
    {
        swap(nums1[i], nums2[j]);
        i++;
    }
    sort(nums1.begin(), nums1.end());
}

//optimal
void merge_(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n - 1;

        while(j>=0)
        {
            if(i>=0 && nums1[i]>nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--]; 
        }
    }

int main()
{

    return 0;
}