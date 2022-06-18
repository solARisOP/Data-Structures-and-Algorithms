#include <iostream>
using namespace std;

int sqrt(int n, int s, int e)
{
    cout<<s<<"  "<<e<<endl;;
    long long int m = (s+e)/2;
    cout<<m<<endl;
    int ans = -1;
    if(s<=e)
    {
        long long int sq = m*m;
        if(sq == n)
        {
            return m;
        }
        if(sq > n)
        {
            cout<<"sq > n"<<endl;
            cout<<endl;
            return sqrt(n, s, m-1);
        }
        else
        {
            cout<<"else"<<endl;
            cout<<endl;
            ans = m;
            return sqrt(n, m+1, e);
        }
    }
    return ans;
}

int main()
{
    int x;
    cin>>x;
    cout<<sqrt(x, 0, x);

    return 0;
}