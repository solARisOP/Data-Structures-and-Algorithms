#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mpp;
    for (char it : s)
        mpp[it]++;
    for (char it : t)
    {
        if (!mpp[it])
            return false;
        mpp[it]--;
    }
    for (char it : s)
        if (mpp[it])
            return false;
    return true;
}

int main()
{
    
    return 0;
}