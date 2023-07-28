#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vi &time, int days, ll limit)
{
    ll sum = 0;
    int day = 1;
    int n = time.size();

    for (int i = 0; i < n; i++)
    {
        sum += time[i];
        if (sum > limit)
        {
            day++;
            sum = time[i];
        }
        if (day > days)
            return 0;
    }

    return 1;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    ll low = *max_element(time.begin(), time.end());
    ll high = 0;
    for (int i = 0; i < m; i++)
    {
        high += time[i];
    }

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        bool x = solve(time, n, mid);

        if (x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{

    return 0;
}