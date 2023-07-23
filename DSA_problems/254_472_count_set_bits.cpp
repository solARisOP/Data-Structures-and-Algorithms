#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int setBits(int N)
{
    // Write Your Code here
    int ans = 0;
    while (N)
    {
        ans += (N & 1);
        N >>= 1;
    }

    return ans;
}

int main()
{
    cout<<(3^2);
}