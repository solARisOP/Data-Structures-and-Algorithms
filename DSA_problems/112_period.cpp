#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    int f_max[n];
    int l_max[n];
    int m = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        m = max(m, sum);
        f_max[i] = m;
        if (sum < 0)
            sum = 0;
    }
    m = INT_MIN;
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += arr[i];
        m = max(m, sum);
        l_max[i] = m;
        if (sum < 0)
            sum = 0;
    }
    m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + k + 1; j < n; j++)
        {
            m = max(m, (f_max[i] + l_max[j]));
        }
    }    
            
    cout << m;
    return 0;
}