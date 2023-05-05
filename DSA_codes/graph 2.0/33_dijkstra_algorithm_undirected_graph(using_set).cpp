#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vi dijkstra(int V, vii adj[], int S)
{
    // Code here
    set<pii> st;

    vi dist(V, 1e9);
    dist[S] = 0;

    st.insert({0, S});

    while (!st.empty())
    {
        auto it = *(st.begin());

        int node = it.second;
        int dist_so_far = it.first;

        st.erase(it);

        for (auto it : adj[node])
        {
            int u = it[0];
            int wt = it[1];

            if (dist_so_far + wt < dist[u])
            {
                if (dist[u] != 1e9)
                    st.erase({dist[u], u});
                dist[u] = dist_so_far + wt;
                st.insert({dist[u], u});
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}