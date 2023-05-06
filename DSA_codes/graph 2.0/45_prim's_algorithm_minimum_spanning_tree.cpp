#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pii, vp, greater<pii>> pq;

    pq.push({0, 0});
    vi vis(V, 0);

    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node])
            continue;
        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int u = it[0];
            int edw = it[1];

            if (!vis[u])
            {
                pq.push({edw, u});
            }
        }
    }

    return sum;
}

int main()
{

    return 0;
}