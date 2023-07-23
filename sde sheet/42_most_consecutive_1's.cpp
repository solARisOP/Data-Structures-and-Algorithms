#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    int i = 0;
    while (i < n)
    {
        int cnt = 0;
        while (i < n && !nums[i])
            i++;
        while (i < n && nums[i])
        {
            i++;
            cnt++;
        }

        maxi = max(cnt, maxi);
    }

    return maxi;
}

int main()
{

    return 0;
}