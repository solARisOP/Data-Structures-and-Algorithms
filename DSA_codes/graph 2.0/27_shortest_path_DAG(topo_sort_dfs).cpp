#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void toposort(int node, vi &vis, vp adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            toposort(v, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vp adj[N];

    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }
    vi vis(N, 0);
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            toposort(i, vis, adj, st);
    }
    vi dist(N, 1e9);

    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for (int &it : dist)
        if (it == 1e9)
            it = -1;

    return dist;
}

int main()
{

    return 0;
}