#include <bits/stdc++.h>
#include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    // code here
    vii mat(n, vi(m, 0));
    int size = operators.size();

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    DisjointSet ds(n * m);
    int cnt = 0;
    vi vec;
    for (int i = 0; i < size; i++)
    {
        int x = operators[i][0];
        int y = operators[i][1];
        if (mat[x][y])
        {
            vec.push_back(cnt);
            continue;
        }

        cnt++;
        mat[x][y] = 1;
        for (int d = 0; d < 4; d++)
        {
            int nr = x + dr[d];
            int nc = y + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc])
            {
                if (ds.findUPar(x * m + y) != ds.findUPar(nr * m + nc))
                {
                    ds.unionBySize(x * m + y, nr * m + nc);
                    cnt--;
                }
            }
        }

        vec.push_back(cnt);
    }

    return vec;
}

int main()
{

    return 0;
}