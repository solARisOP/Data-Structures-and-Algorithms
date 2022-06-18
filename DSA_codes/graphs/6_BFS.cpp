#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<int> adj[], int n)
{
    vector<int> vis(n+1, 0);
    vector<int> bfs;
    for (int i = 6; i <= n; i++) // this for loop is for components of graph if existed
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node]) // this loop is for the nodes while are linked to this particular node
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }  
            }
        }
    }

    return bfs;
}

void adjacency_list(vector<int> *adj, int n, int e)
{
    for (int i = 0; i < e; i++)
    {
        int u, v; // u and v are nodes 
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}

int main()
{
    int n, e;
    cin>>n>>e; 

    vector<int> adj_l[n+1]; 
    adjacency_list(adj_l, n, e);
    cout<<endl;
    for (int i = 1; i < n+1; i++)
    {
        for(auto j : adj_l[i])
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto i : BFS(adj_l, n)) cout<<i<<"  ";
    return 0;
}