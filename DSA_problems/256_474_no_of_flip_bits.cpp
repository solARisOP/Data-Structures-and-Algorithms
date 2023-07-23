#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int countBitsFlip(int a, int b)
{

    // Your logic here
    int xori = (a ^ b);

    int ans = 0;
    while (xori)
    {
        ans += (xori & 1);
        xori >>= 1;
    }

    return ans;
}

int main()
{

    return 0;
}