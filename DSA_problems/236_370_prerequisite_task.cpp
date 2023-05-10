#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool prerequisiteTask(vector<vector<int>>& dependency, int n, int m) {
    // Write your code here.
    vi adj[n+1];
    for(auto it : dependency)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    queue<int> q;
    vi indegree(n+1, 0);
    for(int i = 1; i<=n; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for(int i = 1; i<=n; i++)
    {
        if(!indegree[i]) q.push(i);
    }
    int cnt= 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cnt++;
        for(int it : adj[node])
        {
            indegree[it]--;
            if(!indegree[it])
            {
                q.push(it);
            }
        }
    }

    if(cnt == n) return true;
    return false;
}

int main()
{
    
    return 0;
}