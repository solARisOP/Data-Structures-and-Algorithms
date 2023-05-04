#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

vector<int> topoSort(int V, vector<int> adj[])
{
    vi indegree(V, 0), ans;

    for (int i = 0; i < V; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!indegree[i]) q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i : adj[node])
        {
            indegree[i]--;
            if (!indegree[i]) q.push(i);
        }
    }

    return ans;
}

int main()
{

    return 0;
}