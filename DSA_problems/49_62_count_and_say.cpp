#include <bits/stdc++.h>
using namespace std;

string countno(vector<int> v, int i, int n)
{
    if(i == n)
    {
        string s;
        for (int j = 0; j < v.size(); j++)
        {
            s.push_back(v[j]+'0');
        }
        return s;
    }
    int l = v.size();
    int it =0;
    int c =1;
    while(it<l)
    {
        if(v[it] == v[it+1] && it+1 < l)
        {
            c++;
            it++;
        }
        else
        {
            v.push_back(c);
            v.push_back(v[it]);
            it++;
            c=1;
        }
    }
    v.erase(v.begin(), v.begin()+l);
    return countno(v, i+1, n);

}

string countAndSay(int n) 
{
    string s;
    if(n==1)
    {
        s.push_back(1+'0');
        return s;
    }
    vector<int> v(2,1);
    return countno(v,2,n);
            
}

int main()
{
    int n;
    cin>>n;
    cout<<countAndSay(n);
}