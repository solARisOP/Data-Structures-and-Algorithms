#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>
#define d 256

// rabin karp
int rabin(string pat, string txt)
{
    int q = INT_MAX;
    int m = pat.length();
    int n = txt.length();
    long long p = 0;
    long long t = 0;
    long long h = 1;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    cout << n << " " << m << endl;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat.at(i)) % q;
        t = (t * d + txt.at(i)) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (pat[j] != txt[j + i])
                {
                    break;
                }
            }
            if (j == m)
                return i;
        }
        if (i < n - m)
        {
            t = (d * (t - (txt.at(i)) * h) + (txt.at(i + m))) % q;
            if (t < 0)
                t += q;
        }
    }
    return -1;
}

int strStr(string haystack, string needle)
{
    return needle.size() <= haystack.size() ? rabin(needle, haystack) : -1;
}

// z search
int strStr(string s, string pattern)
{
    int m = s.size(), n = pattern.size();
    string new_string = pattern + '#' + s;
    int i = 0;
    vector<int> z, ans;
    while (i < new_string.size())
    {
        if (i <= pattern.length())
            z.push_back(0);
        else
        {
            int left = 0, right = i;
            while (new_string[left] == new_string[right] && right < new_string.length())
            {
                left++, right++;
            }
            if (left == n)
                return (i - n - 1);
        }
        i++;
    }

    return -1;
}

int main()
{

    return 0;
}