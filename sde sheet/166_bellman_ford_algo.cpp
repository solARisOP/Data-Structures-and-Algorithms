#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vi dist(n+1, 1e8);
    dist[src] = 0;
    for(int i=0; i<n-1; i++)
    {
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v])
            {
                dist[v]  = dist[u] + wt;

            }
        }
    }

    return dist;
}

int main()
{
    
    return 0;
}