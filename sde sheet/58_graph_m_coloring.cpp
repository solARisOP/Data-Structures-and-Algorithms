#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool is_valid(bool graph[101][101], int node, int rang, vi &color, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && graph[node][i] && color[i] == rang)
            return false;
    }

    return true;
}

bool coloring(bool graph[101][101], int m, int n, int node, vi &color)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (is_valid(graph, node, i, color, n))
        {
            color[node] = i;
            if (coloring(graph, m, n, node + 1, color))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vi color(n, 0);
    return coloring(graph, m, n, 0, color);
}

int main()
{

    return 0;
}