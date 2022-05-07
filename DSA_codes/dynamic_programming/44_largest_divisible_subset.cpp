#include <bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr) // sol. taken from dp-42 different algorithm with a slight change
{
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1, last_ind = 0;
    sort(arr.begin(), arr.end()); // we can sort here as it gives us some ease and here they asked us about subset not subsequence so order doesn't matter
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i]) // if the current element is divisible by the previous element that means the element is divisilbe by all the elements stored before the previous element
            {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last_ind = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[last_ind]);
    while (hash[last_ind] != last_ind)
    {
        last_ind = hash[last_ind];
        temp.push_back(arr[last_ind]);
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{

    return 0;
}