#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int main()
{
    int n = 50;

    // hollow rectangle
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=0 && i!=n-1)
            {
                if(j==0 || j ==n-1) cout<<"*";
                else cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }

    // binary right angled triangle
    bool var =1;
    for(int i=0; i<n; i++)
    {
        bool pr = var;
        for(int j=0; j<=i; j++)
        {
            cout<<pr;
            pr = !pr;
        }
        cout<<endl;
        var = !var;
    }
    return 0;
}