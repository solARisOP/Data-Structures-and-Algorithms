#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1, j = 0;

    while (arr1[i] > arr2[j] && (i >= 0 && j < m))
    {
        swap(arr1[i], arr2[j]);
        --i;
        ++j;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{

    return 0;
}