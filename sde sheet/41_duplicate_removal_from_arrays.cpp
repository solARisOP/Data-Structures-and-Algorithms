#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, l = 0, h = 0;
    for (i = 0; h < n && i < n; i++)
    {
        while (h < n && nums[l] == nums[h])
            h++;
        nums[i] = nums[l];
        l = h;
    }

    return i;
}

int main()
{

    return 0;
}