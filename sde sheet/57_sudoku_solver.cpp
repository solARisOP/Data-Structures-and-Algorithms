#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool is_safe(char val, int row, int col, vector<vector<char>>& board)
    {
        for(int i = 0; i<9; i++)
        {
            if(board[i][col] == val) return 0;
            if(board[row][i] == val) return 0;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false;
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char val='1'; val<='9'; val++)
                    {
                        if(is_safe(val, i, j, board))
                        {
                            board[i][j] = val;
                            if(solve(board)) return true;
                            board[i][j] = '.';

                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

int main()
{
    
    return 0;
}