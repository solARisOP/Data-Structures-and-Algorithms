#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define str string 

// memoization
int solve(int n1, int n2, int n3, str &A, str &B, str &C, vector<vii> &dp)
{
    if(n1< 0 || n2< 0 || n3 < 0) return 0;
    
    if(dp[n1][n2][n3] != -1) return dp[n1][n2][n3];
    
    
    if(A[n1] == B[n2] && A[n1] == C[n3]) return dp[n1][n2][n3] = 1+solve(n1-1, n2-1, n3-1, A, B, C, dp);

    else return dp[n1][n2][n3] = max({solve(n1-1, n2, n3, A, B, C, dp), solve(n1, n2-1, n3, A, B, C, dp), solve(n1, n2, n3-1, A, B, C, dp)});
    
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vii> dp(n1, vii(n2, vi(n3, -1)));
    return solve(n1-1, n2-1, n3-1, A,B,C, dp);
}

// memoization index right shift
int solve_RS(int n1, int n2, int n3, str &A, str &B, str &C, vector<vii> &dp)
{
    if(n1== 0 || n2== 0 || n3 == 0) return 0;
    
    if(dp[n1][n2][n3] != -1) return dp[n1][n2][n3];
    
    
    if(A[n1-1] == B[n2-1] && A[n1-1] == C[n3-1]) return dp[n1][n2][n3] = 1+solve(n1-1, n2-1, n3-1, A, B, C, dp);

    else return dp[n1][n2][n3] = max({solve(n1-1, n2, n3, A, B, C, dp), solve(n1, n2-1, n3, A, B, C, dp), solve(n1, n2, n3-1, A, B, C, dp)});
    
}
int LCSof3_RS(string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vii> dp(n1+1, vii(n2+1, vi(n3+1, -1)));
    return solve(n1, n2, n3, A,B,C, dp);
}

// tabulation
int LCSof3_tab(string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vii> dp(n1+1, vii(n2+1, vi(n3+1, 0)));
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            for(int k=1; k<=n3; k++)
            {
                if(A[i-1] == B[j-1] && A[i-1] == C[k-1]) dp[i][j][k] = 1+dp[i-1][j-1][k-1];

                else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }       
        }
    }
    return dp[n1][n2][n3];
}

// tabulation with space optimization
int LCSof3_tab(string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vii curr(n2+1, vi(n3+1, 0)), prev(n2+1, vi(n3+1, 0));
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n2; j++)
        {
            for(int k=1; k<=n3; k++)
            {
                if(A[i-1] == B[j-1] && A[i-1] == C[k-1]) curr[j][k] = 1+prev[j-1][k-1];

                else curr[j][k] = max({prev[j][k],curr[j-1][k], curr[j][k-1]});
            }       
        }
        prev = curr;
    }
    return curr[n2][n3];
}
int main()
{
    
    return 0;
}