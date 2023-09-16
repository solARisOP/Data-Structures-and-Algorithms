#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

string getPermutation(int n, int k)
{
    vi nums;
    int fac = 1;
    for (int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fac *= i;
    }
    nums.push_back(n);
    string ans = "";
    k = k - 1;
    while (1)
    {
        int ind = k / fac;
        ans.push_back(nums[ind] + '0');
        nums.erase(begin(nums) + ind);
        if (ans.size() == n)
            break;
        k %= fac;
        fac /= nums.size();
    }

    return ans;
}

int main()
{
    
    return 0;
}