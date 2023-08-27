#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int minDistance(string trans, string res)
{
    int m = trans.size(), n = res.size();

    vi prev(n + 1, -1), curr(n + 1, -1);
    for (int i = 0; i <= n; i++) prev[i] = i;

    for (int i = 1; i <= m; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (trans[i - 1] == res[j - 1])
                curr[j] = prev[j - 1];

            else
            {
                int ins = 1 + curr[j - 1];
                int del = 1 + prev[j];
                int rep = 1 + prev[j - 1];

                curr[j] = min({ins, rep, del});
            }
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{

    return 0;
}