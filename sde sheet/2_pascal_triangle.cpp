#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<vector<int>> generate(int numRows)
{
    vvi ans;
    for (int i = 1; i <= numRows; i++)
    {
        vi arr(i, 1);
        for (int j = 1; j < i-1; j++)
        {
            arr[j] = ans[i-2][j-1] + ans[i-2][j];
        }
        ans.push_back(arr);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(auto it : generate(n))
    {
        for(auto num : it) cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}