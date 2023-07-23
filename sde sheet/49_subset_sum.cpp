#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(int i, int sum, vi arr, vi &ans, int N)
{
    if (i == N)
    {
        ans.push_back(sum);
        return;
    }
    solve(i + 1, sum, arr, ans, N);
    solve(i + 1, sum + arr[i], arr, ans, N);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vi ans;
    solve(0, 0, arr, ans, N);
    return ans;
}

int main()
{  
    set<int> s;
    vi ans(s.begin(), s.end());
    return 0;
}