#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int myPow(long long x, int n, int m)
{
    if (n == 0)
        return 1;
    long long power = abs(n);
    long long extra = 1;

    while (power != 1)
    {
        if (power % 2 == 1)
            extra *= x;
        x *= x;
        power /= 2;
        if (x > m)
            return 2;
    }

    x *= extra;
    if (x > m)
        return 2;

    return (x == m) ? 1 : 0;
}

int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1, high = m;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        int val = myPow(mid, n, m);

        if (val == 1)
            return mid;
        else if (!val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{

    return 0;
}