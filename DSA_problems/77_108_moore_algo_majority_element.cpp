#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{

    int x = a[0], count = 1;

    for (int i = 1; i < size; i++)
    {
        if (a[i] == x)
            count++;
        else
        {
            if (count > 1)
                count--;
            else
                x = a[i];
        }
    }

    int result = 0;
    if (count >= 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i] == x)
                result++;
        }
    }

    if (result > size / 2)
        return x;

    return -1;
}

int main()
{

    return 0;
}