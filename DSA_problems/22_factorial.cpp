#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &fac, int n)
{
    int carry = 0;
    for(int i=0; i<fac.size(); i++)
    {
        int data = fac[i] * n + carry;
        fac[i] = data % 10;
        carry = data / 10;
    }
    // for (int i = 0; i < fac.size(); i++)
    // {
    //     // cout<<fac[i];
    // }
    // cout<<"/";
    while(carry)
    {
        fac.push_back(carry % 10);
        carry /= 10;
    }
    // for (int i = 0; i < fac.size(); i++)
    // {
    //     cout<<fac[i];
    // }
    // cout<<endl;
}
   
vector<int> factorial(int N)
{
    vector<int> fac = {1};
    for(int i=2; i<=N; i++)
    {
        multiply(fac,i);
    }
    
    reverse(fac.begin(),fac.end());
    return (fac);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v (factorial(n));
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }

    return 0;
}