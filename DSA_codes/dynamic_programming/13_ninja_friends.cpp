#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int r, int R, int c1, int c2, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (c1 < 0 || c2 < 0 || c1 >= c || c2 >= c)
        return -1e9;
    if (r == R - 1)
    {
        if (c1 == c2)
            return grid[r][c1];
        else
            return grid[r][c1] + grid[r][c2];
    }
    if (dp[r][c1][c2] != -1)
        return dp[r][c1][c2];

    int maxi = 0;

    for (int dji = -1; dji <= 1; dji++) // for every move of alice there will be 3 moves of bob and the moves can be either a column same, increase or decrease because the row will always increase and they both will be in same row
    {
        for (int dji2 = -1; dji2 <= 1; dji2++)
        {
            int value = 0;
            if (c1 == c2)
                value = grid[r][c1]; // if they land on same cell then only one can take the choclate
            else
                value = grid[r][c1] + grid[r][c2]; // if they land on diff cell both will take the choclates.

            value += solve(r + 1, R, c1 + dji, c2 + dji2, c, grid, dp);
            if (value > maxi)
                maxi = value;
        }
    }

    return dp[r][c1][c2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, r, 0, c - 1, c, grid, dp);
}

// tabulation
int maximumChocolates_tab(int r, int c, vector<vector<int>> &grid)
{

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e9;
                for (int dji = -1; dji <= 1; dji++)
                {
                    for (int dji2 = -1; dji2 <= 1; dji2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + dji >= 0 && j1 + dji < c && j2 + dji2 >= 0 && j2 + dji2 < c)
                            value += dp[i + 1][j1 + dji][j2 + dji2];
                        else
                            value += -1e9;

                        if (value > maxi)
                            maxi = value;
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c - 1];
}

// tabulation with space optimization
int maximumChocolates_tab1(int r, int c, vector<vector<int>> &grid)
{

    vector<vector<int>> dp(c,vector<int>(c,0)), curr(c,vector<int>(c,0));

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[j1][j2] = grid[r - 1][j1];
            else
                dp[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e9;
                for (int dji = -1; dji <= 1; dji++)
                {
                    for (int dji2 = -1; dji2 <= 1; dji2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + dji >= 0 && j1 + dji < c && j2 + dji2 >= 0 && j2 + dji2 < c)
                            value += dp[j1 + dji][j2 + dji2];
                        else
                            value += -1e9;

                        if (value > maxi)
                            maxi = value;
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        dp = curr;
    }

    return dp[0][c - 1];
}

int main()
{
    vector<vector<int>> grid = {{
                                    2,
                                    3,
                                    1,
                                    2,
                                },
                                {
                                    3,
                                    4,
                                    2,
                                    2,
                                },
                                {
                                    5,
                                    6,
                                    3,
                                    5,
                                }};
    cout << maximumChocolates_tab(3, 4, grid);
    return 0;
}