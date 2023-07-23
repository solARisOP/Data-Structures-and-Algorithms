#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int findPosition(int n)
{
    // code here
    if (!n || __builtin_popcount(n) > 1)
        return -1;

    int cnt = 0;
    while (n)
    {
        n >>= 1;
        cnt++;
    }

    return cnt;
}

int main()
{

    return 0;
}