#include <bits/stdc++.h>
using namespace std;

int countSquares(int N)
{
    int count = 0;
    for (int i = 1; i < N; i++)
    {
        if ((i * i) < N)
            count++;
        else
            break;
    }

    return count;
}

int main()
{
    
    return 0;
}