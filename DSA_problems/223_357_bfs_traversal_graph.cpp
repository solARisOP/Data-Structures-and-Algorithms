#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vi vis(V, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    vi bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        bfs.push_back(node);
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main()
{

    return 0;
}