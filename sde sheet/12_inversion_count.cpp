#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void merge(vector<ll>&arr, ll low, ll mid, ll high, ll &ans)
{
    vector<ll> temp;
    ll i = low;
    ll j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            ans+=(mid-i+1);
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

    for (ll i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<ll> &nums, ll low, ll high, ll &ans)
{
    if (low >= high)
        return;

    ll mid = (low + high) / 2;
    mergesort(nums, low, mid, ans);
    mergesort(nums, mid + 1, high, ans);
    merge(nums, low, mid, high, ans);
}

long long getInversions(long long *arr, ll n){
    // Write your code here.
    vector<ll> nums(arr, arr+n);
    ll ans = 0;
    mergesort(nums, 0, n - 1, ans);
    return ans;
}

int main()
{
    
    return 0;
}