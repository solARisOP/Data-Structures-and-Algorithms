#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// brute
int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    int n = version1.length(), m = version2.length();
    while (i < n && j < m)
    {
        while (i < n && version1[i] == '0') i++;
        while (j < m && version2[j] == '0') j++;

        string a = "", b = "";
        int x = i, y = j;
        while (x < n && version1[x] != '.') a += version1[x++];
        while (y < m && version2[y] != '.') b += version2[y++];
        if (x - i < y - j)return -1;
        if (x - i > y - j) return 1;

        int z = a.compare(b);
        if (z < 0) return -1;
        else if (z) return 1;

        i = x + 1;
        j = y + 1;
    }
    while (j < m)
    {
        if (version2[j] != '0' && version2[j] != '.') return -1;
        j++;
    }
    while (i < n)
    {
        if (version1[i] != '0' && version1[i] != '.') return 1;
        i++;
    }
    
    return 0;
}

// optimal
int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    int n = version1.length(), m = version2.length();
    while (i < n || j < m)
    {
        int a = 0, b = 0;
        int x = i, y = j;
        while (x < n && version1[x] != '.') a = a * 10 + (version1[x++] - '0');
        while (y < m && version2[y] != '.') b = b * 10 + (version2[y++] - '0');
        i = x + 1;
        j = y + 1;
        if (a < b) return -1;
        if (a > b) return 1;
    }

    return 0;
}

int main()
{

    return 0;
}