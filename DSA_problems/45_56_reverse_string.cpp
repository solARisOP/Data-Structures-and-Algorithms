#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) 
{   
    for(int i=0; i < s.size()/2; i++)
    {
        swap(s[i], s[s.size()-1-i]);
    }
}
int main()
{
    int n; 
    char e;
    cin>>n;
    vector<char> s;
    for (int i = 0; i < n; i++)
    {
        cin>>e;
        s.push_back(e);
    }
    reverseString(s);
    for (int i = 0; i < n; i++)
    {
        cout<<s[i]<<" ";
    }
    

    return 0;
}