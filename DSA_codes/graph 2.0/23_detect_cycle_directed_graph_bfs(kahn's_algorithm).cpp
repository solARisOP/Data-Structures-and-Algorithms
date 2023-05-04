#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool isCyclic(int V, vector<int> adj[])
{
    // code here

    vi indegree(V, 0);

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

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (int i : adj[node])
        {
            indegree[i]--;
            if (!indegree[i]) q.push(i);
        }
    }

    if (cnt == V) return false;

    return true;
}

int main()
{

    return 0;
}