#include <bits/stdc++.h>
using namespace std;

int check(string s, string in[], int row, int col, int rc, int cc)
{
    int found =0;
    int n = s.size();
    if(col +n-1 < cc)
    {
        int t =0;
        for (int i = col; i < cc && t<n; i++, t++)
        {
            if(in[row][i] != s[t])
            {
                break;
            }
        }
        if(t == n) found++;
    }    
    if(col -n+1 >= 0)
    {
        int t =0;
        for (int i = col; t<n; i--, t++)
        {
            if(in[row][i] != s[t])
            {
                break;
            }
        }
        if(t == n) found++;
    }
    if(row +n-1 < rc)
    {
        int t =0;
        for (int i = row; i<rc && t<n; i++, t++)
        {
            if(in[i][col] != s[t])
            {
                break;
            }
        }
        if(t == n) found++;
    }
    if(row -n+1 >= 0)
    {
        int t =0;
        for (int i = row; i>=0 && t<n; i--, t++)
        {
            if(in[i][col] != s[t])
            {
                break;
            }
        }
        if(t == n) found++;
    }
    return found;
}

int solve(string s,string in [], int rc, int cc)
{
    int found = 0;
    char c = s[0];
    for (int i = 0; i < rc; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            if(in[i][j] == c)
            {
                found+=check(s, in, i, j, rc, cc);

            }
        }        
    }
    return found;    
}

int main()
{
     string a[7] = {"NITISH",
                    "GHYTRF",
                    "CSABBB",
                    "IIGBBB",
                    "GTIBBB",
                    "AICBBB",
                    "MNIGAM"};

    string str = "NITISH";
    cout<<solve(str, a, 7, 7);
    return 0;
}