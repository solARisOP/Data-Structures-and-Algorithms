#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(int src, int n, vector<pair<int, int>> *adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> dist(n+1, INT_MAX);

    dist[0] = -1;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        for(auto i : adj[node])
        {
            if(dist[node] + i.second < dist[i.first])
            {
                dist[i.first] = dist[node] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    return dist;
}

void add_edge(int u, pair<int, int> p, vector<pair<int, int>> *adj)
{
    adj[u].push_back(p);
}

int main()
{
    vector<pair<int, int>> adj[6];

    add_edge(1, {2,2}, adj);
    add_edge(1, {4,1}, adj);
    add_edge(2, {1,2}, adj);
    add_edge(2, {5,5}, adj);
    add_edge(2, {3,4}, adj);
    add_edge(3, {2,4}, adj);
    add_edge(3, {4,3}, adj);
    add_edge(3, {5,1}, adj);
    add_edge(4, {1,1}, adj);
    add_edge(4, {3,3}, adj);
    add_edge(5, {2,5}, adj);
    add_edge(5, {3,1}, adj);

    for(auto i : shortest_path(1, 5, adj)) cout<<i<<"   ";

    return 0;
}