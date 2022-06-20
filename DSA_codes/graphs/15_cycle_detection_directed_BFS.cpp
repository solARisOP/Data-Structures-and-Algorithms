#include <bits/stdc++.h>
using namespace std;

bool toposort(int n, vector<int> *adj)
{
    vector<int> indegree(n+1, 0);
    queue<int> q;
    for (int i = 1; i < n+1; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++; // calculating the indegree of all nodes
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        if(indegree[i] == 0) q.push(i); // all nodes of indegree 0 pushed into queue 
    }
    
    int cnt =0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for(auto i : adj[node])
        {
            --indegree[i];
            if(indegree[i] == 0) q.push(i); // if indegree is 0 then we push it in the queue
        }
    }
    
    if(cnt == n) return false; // if the topological sort is possible for this graph then it sure is not an cyclic graph, because topological sort is only possible for DAG(directed acylic graphs)
    return true;
}

void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
}

int main()
{
    vector<int> adj[10];
    add_edge(1, 2, adj);
    add_edge(2, 3, adj);
    add_edge(3, 4, adj);
    add_edge(3, 6, adj);
    add_edge(4, 5, adj);
    add_edge(6, 5, adj);
    add_edge(7, 2, adj);
    add_edge(7, 8, adj);
    add_edge(8, 9, adj);
    add_edge(9, 7, adj);


    cout<<toposort(9, adj);

    return 0;
}