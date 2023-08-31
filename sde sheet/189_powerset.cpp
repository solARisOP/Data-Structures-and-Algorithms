#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<vector<int>> pwset(vector<int>v)
{
    vvi ans;
    //Write your code here
    int n = v.size();
    for(int i=0; i<(1<<n); i++)
    {
        vi temp;
        for(int j=0; j<n; j++)
        {
            if (i & (1<<j))
            {
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    
    return 0;
}