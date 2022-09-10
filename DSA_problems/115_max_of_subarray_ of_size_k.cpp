#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && q.front() == i - k)
            q.pop_front();
        while (!q.empty() && arr[q.back()] <= arr[i])
            q.pop_back();

        q.push_back(i);
        if (i >= k - 1)
            ans.push_back(arr[q.front()]);
    }

    return ans;
}


int main()
{

    return 0;
}