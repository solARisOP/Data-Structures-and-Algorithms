#include <bits/stdc++.h>
using namespace std;

int minjumps(int arr[], int n)
{
    if(n <= 1) return 0;
    if(arr[0] == 0) return -1;
    if(arr[0]>=n-1) return 1;
    int pos =0;
    int jump = 0, t=1;
    while (pos<n-1)
    {       
        int max_pos = INT_MIN;
        for (int j = t; j <= arr[pos]; j++)
        {
            if (arr[j] > max_pos)
            {
                max_pos = arr[j];
            }
        }
        max_pos = max(arr[pos], max_pos);
        if(max_pos == 0) return -1;
        pos += max_pos;
        t = pos+1;
        ++jump;
    }

    return jump;
}

int main()
{
    int a[] = {5, 2, 2, 1, 2, 2, 6, 7, 6, 8, 9};
    int n = sizeof(a) / sizeof(int);
    cout << minjumps(a, n);
    return 0;
}