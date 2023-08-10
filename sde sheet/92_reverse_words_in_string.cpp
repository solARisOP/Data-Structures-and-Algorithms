#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

string reverseWords(string s)
{
    int n = s.length();
    reverse(s.begin(), s.end());
    int start = 0, end = 0, inc = 0;
    while (inc < n)
    {
        while (inc < n && s[inc] != ' ')
            s[end++] = s[inc++];
        if (start < end)
        {
            reverse(s.begin() + start, s.begin() + end);
            if (end == n)
                break;
            s[end++] = ' ';
            start = end;
        }
        inc++;
    }
    if (end > 0 && s[end - 1] == ' ')
        s.resize(end - 1);
    else
        s.resize(end);
    return s;
}

int main()
{

    return 0;
}