#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int eggDrop_SO(int egg, int flr)
{
    // your code here
    vi curr(flr + 1, 0), prev(flr + 1, 0);
    for (int f = 1; f <= flr; f++)
    {
        curr[f] = f;
        prev[f] = f;
    }

    for (int e = 2; e <= egg; e++)
    {
        for (int f = 2; f <= flr; f++)
        {
            int mini = INT_MAX;

            for (int k = 1; k <= f; k++)
            {
                int temp = 1 + max(prev[k - 1], curr[f - k]);
                mini = min(mini, temp);
            }
            curr[f] = mini;
        }
        prev = curr;
    }
    return curr[flr];
}

int main()
{
    
    return 0;
}