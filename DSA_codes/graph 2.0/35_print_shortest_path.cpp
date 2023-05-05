#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vi shortestPath(int n, int m, vii &edges)
{
    // Code here
    vp adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vp dist(n + 1, {1e9, 1});

    set<pii> st;

    st.insert({0, 1});

    dist[1] = {0, 1};

    while (!st.empty())
    {
        auto it = *(st.begin());

        int node = it.second;
        int dis_so_far = it.first;

        st.erase(it);

        for (auto x : adj[node])
        {
            int u = x.first;
            int wt = x.second;

            if (dis_so_far + wt < dist[u].first)
            {
                if (dist[u].first != 1e9)
                    st.erase({dist[u].first, u});
                dist[u].first = dis_so_far + wt;
                dist[u].second = node;
                st.insert({dist[u].first, u});
            }
        }
    }
    if (dist[n].first == 1e9)
        return {-1};
    vi ans;
    int ind = n;
    while (1)
    {
        ans.push_back(ind);
        if (ind == 1)
            break;
        ind = dist[ind].second;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}