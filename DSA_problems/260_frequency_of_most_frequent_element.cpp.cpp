#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

//  brute force
int maxFrequency(vector<int> &nums, int k)
{
    sort(begin(nums), end(nums));
    int n = nums.size();
    int maxi = 1, x = n - 1;
    while (maxi < x + 1 && x > 0)
    {
        int cnt = 1, freq = k;
        for (int i = x - 1; i >= 0; i--)
        {
            if (nums[x] - nums[i] <= freq)
            {
                freq -= (nums[x] - nums[i]);
                cnt++;
            }
            else
                break;
        }
        maxi = max(cnt, maxi);
        x--;
    }

    return maxi;
}

// optimized
int maxFrequency(vector<int> &nums, int k)
{
    sort(begin(nums), end(nums));
    int n = nums.size();
    int maxi = 1;
    int i = 0, j = i + 1;
    long long sum = nums[i];
    while (j < n)
    {
        long long occ = (long long)nums[j] * (long long)(j - i);
        while (i < j && occ - sum > k)
        {
            sum -= nums[i];
            occ -= nums[j];
            i++;
        }
        if (i < j)
            maxi = max(maxi, j - i + 1);
        sum += nums[j];
        j++;
    }

    return maxi;
}

// optimized - 2
int maxFrequency(vector<int> &nums, int k)
{
    sort(begin(nums), end(nums));
    int n = nums.size();
    int maxi = 1;
    int i = 0, j = i + 1;
    long long sum = nums[i];
    while (j < n)
    {
        while (i < j && (sum + k) / nums[j] < (j - i))
        {
            sum -= nums[i];
            i++;
        }
        if (i < j)
            maxi = max(maxi, j - i + 1);
        sum += nums[j];
        j++;
    }
    
    return maxi;
}

int main()
{
    vi nums = {1, 4, 8, 13};
    int k = 5;
    cout << maxFrequency(nums, k);
    return 0;
}