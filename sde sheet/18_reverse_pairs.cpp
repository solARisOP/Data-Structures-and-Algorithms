#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void merge(vi &arr, int low, int mid, int high, int &ans)
{
    int x = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (x <= high && (ll)arr[x] * (ll)2 < (ll)arr[i])
            x++;
        ans += (x - mid - 1);
    }

    vi temp;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergesort(vi &nums, int low, int high, int &ans)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergesort(nums, low, mid, ans);
    mergesort(nums, mid + 1, high, ans);
    merge(nums, low, mid, high, ans);
}

int reversePairs(vector<int> &nums)
{
    int ans = 0;
    mergesort(nums, 0, nums.size() - 1, ans);
    return ans;
}

int main()
{

    return 0;
}