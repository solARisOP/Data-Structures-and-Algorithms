#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int n = nums.size();
    int xori = 0;

    for (int i = 0; i < n; i++)
    {
        xori ^= nums[i];
    }

    xori = xori & ~(xori - 1);

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (xori & (nums[i]))
            a ^= nums[i];
        else
            b ^= nums[i];
    }

    if (a > b)
        return {b, a};
    else
        return {a, b};
}

int main()
{

    return 0;
}