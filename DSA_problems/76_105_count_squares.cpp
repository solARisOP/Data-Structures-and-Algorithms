#include <bits/stdc++.h>
using namespace std;

int middle(int a, int b, int c)
{
    if (((a < b) && (b < c)) || ((c < b) && (b < a)))
        return b;
    else if (((a > b) && (a < c)) || ((a > c) && (a < b)))
        return a;
    return c;
}

int main()
{

    return 0;
}