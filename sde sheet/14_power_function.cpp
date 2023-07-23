#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

double myPow(double x, int n)
{
    if (n == 0) return 1;
    long long power = abs(n);
    double extra = 1;

    while (power != 1)
    {
        if (power % 2 == 1) extra *= x;
        x *= x;
        power /= 2;
    }

    x *= extra;
    return (n < 0) ? 1 / x : x;
}

int main()
{

    return 0;
}