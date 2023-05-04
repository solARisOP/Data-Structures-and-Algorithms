#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vi adj[N];

    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
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

    if (cnt == N) return true;

    return true;
}

int main()
{

    return 0;
}