#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool is_safe(int row, int col, int n, vector<string> &board)
{
    int r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r--][c] == 'Q')
            return 0;
    }
    r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (board[r--][c--] == 'Q')
            return 0;
    }
    r = row, c = col;
    while (r >= 0 && c < board.size())
    {
        if (board[r--][c++] == 'Q')
            return 0;
    }

    return 1;
}

void solve(int ind, vector<string> &board, vector<vector<string>> &ans)
{
    if (ind == board.size())
    {
        ans.push_back(board);
        return;
    }

    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (is_safe(ind, i, n, board))
        {
            board[ind][i] = 'Q';
            solve(ind + 1, board, ans);
            board[ind][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);
    return 0;
}