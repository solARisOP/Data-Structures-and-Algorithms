#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int setSetBit(int x, int y, int l, int r)
{
    // code here
    int changer = y;
    int len = r - l + 1;
    cout<<__builtin_popcount(changer)<<endl;
    changer >>= (l - 1);
    cout<<__builtin_popcount(changer)<<endl;
    changer <<= (32 - len);
    cout<<__builtin_popcount(changer)<<endl;
    changer >>= (32 - len + 1 - l);
    cout<<__builtin_popcount(changer)<<endl;

    return changer | x;
}

int main()
{
    int x, y, l, r;
    x = 19171;
    y = 15726;
    l = 2;
    r = 9; 
    cout<<setSetBit(x,y,l,r);
    return 0;
}