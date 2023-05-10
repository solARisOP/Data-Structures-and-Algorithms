#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<pair<pii, int>> calculatePrimsMST(int n, int m, vector<pair<pii, int>> &g)
{
    // Write your code here.
    vp adj[n + 1];
    for (auto it : g)
    {
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    pq.push({0, {1, -1}});

    vi vis(n + 1, 0);

    vector<pair<pii, int>> ans;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int dis = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if (vis[node])
            continue;
        vis[node] = 1;
        if (parent != -1)
            ans.push_back({{node, parent}, dis});

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (!vis[v])
            {
                pq.push({wt, {v, node}});
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}