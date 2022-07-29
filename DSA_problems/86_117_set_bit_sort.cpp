#include <bits/stdc++.h>
using namespace std;

static bool com(int a, int b)
{
    int cnt_a = 0, cnt_b = 0;
    while (a)
    {
        if (a & 1)
            cnt_a += 1;
        a = a >> 1;
    }
    while (b)
    {
        if (b & 1)
            cnt_b += 1;
        b = b >> 1;
    }
    return (cnt_a > cnt_b);
}
void sortBySetBitCount(int arr[], int n)
{
    sort(arr, arr + n, com);
}

int main()
{

    return 0;
}