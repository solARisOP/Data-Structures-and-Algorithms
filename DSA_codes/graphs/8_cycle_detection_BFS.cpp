#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(int s, vector<int> *adj, vector<int> &vis)
{
    vis[s] = 1;
    queue<pair<int, int>> q;
    q.push({s,-1});

    while(!q.empty())
    {
        int node = q.front().first;
        int pre = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if(pre != it) return true;
        }
    }

    return false;
}

bool iscycle(vector<int> *adj, int n)
{
    vector<int> vis(n+1, 0);
    for (int i = 1; i < n+1; i++)
    {
        if(!vis[i])
        {
            if(cycle_detection(i, adj, vis)) return true;
        }
    }
    
    return false;
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
    add_edge(9,8,adj);
    add_edge(7,8,adj);
    add_edge(5,8,adj);
    // add_edge(7,6,adj);
    add_edge(6,4,adj);
    add_edge(6,10,adj);
    add_edge(5,4,adj);

    cout<<iscycle(adj, 10);

    return 0;
}