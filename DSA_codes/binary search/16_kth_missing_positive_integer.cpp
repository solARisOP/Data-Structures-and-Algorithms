#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int missingK(vector<int> vec, int n, int k)
{
    // Write your code here.
    if (k < vec[0])
        return k;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        int missing = vec[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high + 1 + k;
}

int main()
{
    
    return 0;
}