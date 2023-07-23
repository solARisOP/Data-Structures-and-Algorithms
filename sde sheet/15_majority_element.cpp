#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int major = 0;
    for (int i = 0; i < n; i++)
    {
        if (!count)
        {
            count = 1;
            major = nums[i];
        }
        else if (major != nums[i])
            --count;
        else
            ++count;
    }

    return major;
}

int main()
{

    return 0;
}