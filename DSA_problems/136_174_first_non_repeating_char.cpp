#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    // Code here
    queue<int> q;
    unordered_map<char, int> mp;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
        mp[A[i]]++;

        while (!q.empty() && mp[q.front()] > 1) q.pop();
        if (!q.empty()) ans.push_back(q.front());
        else if (mp[A[i]] <= 1) ans.push_back(A[i]);
        else ans.push_back('#');
        
        q.push(A[i]);
    }
    return ans;
}

int main()
{
    cout << FirstNonRepeating("aabc");
    return 0;
}