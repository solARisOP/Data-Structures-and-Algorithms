#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int i, int j, int N)
{
    return (i > 0 && j > 0 && i <= N && j <= N);
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    int x = KnightPos[0];
    int y = KnightPos[1];

    int tx = TargetPos[0];
    int ty = TargetPos[1];

    queue<pair<int, pii>> q;
    vii dist(N + 1, vi(N + 1, 1e9));

    q.push({0, {x, y}});
    dist[x][y] = 0;

    int delr[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int delc[] = {-1, 1, 2, 2, -1, 1, -2, -2};
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int row = it.second.first;
        int col = it.second.second;
        int steps = it.first;

        for (int i = 0; i < 8; i++)
        {
            int nr = row + delr[i];
            int nc = col + delc[i];

            if (isvalid(nr, nc, N) && steps + 1 < dist[nr][nc])
            {
                dist[nr][nc] = 1 + steps;
                if (nr == tx && nc == ty)
                    return dist[nr][nc];
                q.push({steps + 1, {nr, nc}});
            }
        }
    }

    return dist[tx][ty];
}

int main()
{

    return 0;
}