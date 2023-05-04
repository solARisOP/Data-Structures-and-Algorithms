#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites)
{
    // code here
    vi adj[N];

    for (int i = 0; i < m; i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    vi indegree(N, 0);

    for (int i = 0; i < N; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (!indegree[i]) q.push(i);
    }

    vi topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int i : adj[node])
        {
            indegree[i]--;
            if (!indegree[i]) q.push(i);
        }
    }

    if (topo.size() == N) return topo;

    return {};
}

int main()
{

    return 0;
}