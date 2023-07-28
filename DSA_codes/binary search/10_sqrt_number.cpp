#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int floorSqrt(int n)
{
    // Write your code here.
    int low = 1, high = n;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;

        if (val <= n)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}

int main()
{

    return 0;
}