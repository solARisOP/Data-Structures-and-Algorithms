#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>
#define d 256

// brute
int repeatedStringMatch(string a, string b)
{
    if (!b.length())
        return 0;
    if (!a.length())
        return -1;

    int reps = b.length() / a.length();
    if (b.length() % a.length())
        reps++;

    int i = 1;
    string temp = a;
    while (i < reps)
    {
        a += temp;
        i++;
    }
    while (i < reps + 2)
    {
        if (a.find(b) != string::npos)
            return i;
        a += temp;
        i++;
    }

    return -1;
}

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
                    break;
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
    return -1;;
}

int repeatedStringMatch_(string a, string b)
{
    if (!b.length())
        return 0;
    if (!a.length())
        return -1;

    int reps = b.length() / a.length();
    if (b.length() % a.length())
        reps++;

    int i = 1;
    string temp = a;
    while (i < reps)
    {
        a += temp;
        i++;
    }
    while (i < reps + 2)
    {
        if (rabin(b, a))
            return i;
        a += temp;
        i++;
    }

    return -1;
}

int main()
{
    cout<<rabin("aaa", "aaaa");
    return 0;
}