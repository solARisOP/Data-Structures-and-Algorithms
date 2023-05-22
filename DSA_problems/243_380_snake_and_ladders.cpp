#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

pair<int, int> pos(int x, int n)
{
    int r = (x - 1) / n;
    int c = (x - 1) % n;
    if (r & 1) c = (n - 1) - c;
    r = (n - 1) - r;
    return {r, c};
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    queue<int> q;
    vi dist(n * n + 1, 1e9);
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next = curr + 1; next <= min(curr + 6, n * n); next++)
        {
            pii it = pos(next, n);
            int row = it.first;
            int col = it.second;

            int dest = (board[row][col] == -1) ? next : board[row][col];
            
            if (dist[dest] > dist[curr] + 1)
            {
                dist[dest] = dist[curr] + 1;
                q.push(dest);
                if (dest == n * n) return dist[n * n];
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}