#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int isvalid(int node, int n, int rang, bool graph[101][101], vi &color)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && graph[i][node] && color[i] == rang)
            return false;
    }

    return true;
}

int coloring(int src, bool graph[101][101], int m, int n, vi &color)
{
    if (src == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isvalid(src, n, i, graph, color))
        {
            color[src] = i;
            if (coloring(src + 1, graph, m, n, color))
                return true;
            color[src] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vi color(n, 0);
    return coloring(0, graph, m, n, color);
}

int main()
{

    return 0;
}