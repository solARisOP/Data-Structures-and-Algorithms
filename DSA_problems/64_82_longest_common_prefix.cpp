#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string s = "";
    int minlength = INT_MAX;
    for (int i = 0; i < strs.size(); i++)
    {
        if (strs[i].size() < minlength)
        {
            minlength = strs[i].size();
        }
    }

    int r, c;
    int t = strs[0].size();
    for (c = 0; c < minlength; c++)
    {
        for (r = 1; r < strs.size(); r++)
        {
            if (strs[r][c] != strs[r - 1][c])
            {
                // cout<<strs[r][c]<<" "<<strs[r-1][c]<<endl;
                return s;
            }
        }
        s.push_back(strs[0][c]);
    }
    
    return s;
}
int main()
{
    vector<string> strs = {"f"};
    cout << longestCommonPrefix(strs);
    return 0;
}