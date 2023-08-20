#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool dfs(int node, int col, vvi &graph, vi &colour)
{
    colour[node] = 1 - col;

    for (int it : graph[node])
    {
        if (colour[it] == -1)
        {
            if (!dfs(it, colour[node], graph, colour))
                return false;
        }
        else if (colour[it] == colour[node])
            return false;
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vi colour(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (colour[i] == -1)
        {
            if (!dfs(i, 0, graph, colour))
                return false;
        }
    }

    return true;
}

int main()
{
    
    return 0;
}