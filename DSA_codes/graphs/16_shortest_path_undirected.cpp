#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(int src, int n, vector<int> *adj)
{
    vector<int> dist(n+1, INT_MAX);
    dist[0] = -1;
    dist[src] = 0;
    queue<int> q;

    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto i : adj[node])
        {
            if(dist[node] + 1 < dist[i])
            {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    return dist;
}

void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[11];

    add_edge(1,2,adj);
    add_edge(3,2,adj);
    add_edge(3,9,adj);
    add_edge(9,8,adj);
    add_edge(7,8,adj);
    add_edge(5,8,adj);
    add_edge(7,6,adj);
    add_edge(6,4,adj);
    add_edge(6,10,adj);
    add_edge(5,4,adj);

    for(auto i : shortest_path(1, 10, adj)) cout<<i<<"  ";

    return 0;
}