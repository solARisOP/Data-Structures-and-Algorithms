#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    // Your code here
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m[sum] == 1 || sum == 0 || arr[i] == 0)
        {
            return 1;
        }
        m[sum] = 1;
    }
    return 0;
}

int main()
{
    int arr[] = {4, 5, -4, -2, 1};
    if (subArrayExists(arr, sizeof(arr) / sizeof(int)))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}