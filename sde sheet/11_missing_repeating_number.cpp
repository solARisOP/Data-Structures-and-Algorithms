#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> repeatedNumber(const vector<int> &nums)
{
    long long n = nums.size();
    long long Sn = (n * (n + 1)) / 2;
    long long Ssn = n * (n + 1) / 2 * (2 * n + 1) / 3;

    long long changed_sum = 0, changed_square_sum = 0;
    for (int i = 0; i < n; i++)
    {
        changed_sum += nums[i];
        changed_square_sum += (long long)nums[i] * (long long)nums[i];
    }
    long long val1 = changed_sum - Sn;
    long long val2 = changed_square_sum - Ssn;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {int(x), int(y)};
}

int main()
{

    return 0;
}