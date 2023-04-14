#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int lcs_SO(int x, int y, string s1, string s2)
{
    // your code here
    vi curr(y + 1, 0), prev(y + 1, 0);

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j)
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }
    return prev[y];
}

int LongestRepeatingSubsequence(string str)
{
    // Code here
    string s1 = str;
    string s2 = str;
    return lcs_SO(s1.length(), s2.length(), s1, s2);
}

int main()
{

    return 0;
}