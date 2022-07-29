#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    unordered_map<char, int> count;
    unordered_map<char, pair<int, int>> pos;
    int maxi =0, start =0;
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
        if(count[s[i]]>2)
        {
            count[s[i]]--;
            start = max(start, pos[s[i]].first+1);
            pos[s[i]].first = pos[s[i]].second;
        }

        else if(count[s[i]] == 1)
        {
            pos[s[i]].first = i;
        }
        
        if(count[s[i]] == 2)
        {
            pos[s[i]].second = i;
        }

        maxi = max(maxi , (i - start + 1));
    }
    
    return maxi;
}

int main()
{
    cout<<solve("abacdhuffgfdhu");
    return 0;
}