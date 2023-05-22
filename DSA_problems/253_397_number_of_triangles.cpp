#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> countTriangles(int v1, vector<vector<int>> &edges2, int v2,
                           vector<vector<int>> &edges1)
{
    // Write your code here.
    vector<vector<bool>> A(v1, vector<bool>(v1, 0)), B(v2, vector<bool>(v2, 0));
    
    for(auto it:edges1)
    {
        A[it[0]][it[1]]=1;
        A[it[1]][it[0]]=1;
    }
    for(auto it:edges2)
    {
        B[it[0]][it[1]]=1;
    }
    
    int c1=0, c2=0;
    
    for(int i =0;i<v2;i++)
    {
        for(int j =0;j<v2;j++)
        {
            for(int k =0;k<v2;k++)
            {
                if(A[i][j] && A[j][k] && A[k][i])
                {
                    c1++;
                }
            }
        }
    }
    
    for(int i =0;i<v2;i++)
    {
        for(int j =0;j<v2;j++)
        {
            for(int k =0;k<v2;k++)
            {
                if( B[i][j] && B[j][k] && B[k][i])
                {
                    c2++;
                }
            }
        }
    }
    c1/=6;
    c2/=3;
    
    return {c2, c1};
}
int main()
{

    return 0;
}