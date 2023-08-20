#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vi adj[v];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    vi indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    vi ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (!indegree[it])
                q.push(it);
        }
    }

    return ans;
}

int main()
{

    return 0;
}