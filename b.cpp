#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
bool isvalid(int i, int j, vector<vector<int>> mat, int A)
{
    if(i >= A || j>= A) return 0;
    if(!mat[i][j]) return 0;    
    return 1;
}

int ans(int i, int j, vector<vector<int>> &mat, int A, vector<vector<int>> &dp)
{   
    if(!isvalid(i, j, mat, A)) return 0;

    if(i == A-1 && j == A-1) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int k = ans(i+1, j, mat, A, dp);
    int q = ans(i, j+1, mat, A, dp);
    
    return dp[i][j] = (k%mod  + q%mod)%mod;
}

int solve(int A, int B) 
{
    vector<vector<int>> mat(A, vector<int>(A, 1));
    vector<vector<int>> dp(A, vector<int>(A, -1));

    for(int i= (A/2)-B; i<= (A/2)+B; i++)
    {
        for(int j = (A/2)-B; j<= (A/2)+B; j++)
        {
            mat[i][j] = 0;
        }
    }
    
    return ans(0, 0, mat, A, dp);
}

int main()
{
    cout<<solve(13, 2);
    return 0;
}