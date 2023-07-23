#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// S.C O(2N)
static bool comp(pii a, pii b)
{
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else
        return a.second > b.second;
}

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    vp trains;
    for (int i = 0; i < n; i++)
    {
        trains.push_back({at[i], 1});
        trains.push_back({dt[i], -1});
    }
    sort(trains.begin(), trains.end(), comp);

    int curr = 0, maxi = 0;
    int sn = trains.size();
    for (int i = 0; i < sn; i++)
    {
        curr += trains[i].second;
        maxi = max(curr, maxi);
    }

    return maxi;
}


// S.C O(1)
int findPlatform(int at[], int dt[], int n)
{
    // Write your code here.

    sort(at, at + n);
    sort(dt, dt + n);

    int plats = 0, maxi = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            plats++;
            i++;
        }
        else
        {
            plats--;
            j++;
        }
        maxi = max(plats, maxi);
    }

    return maxi;
}

int main()
{

    return 0;
}