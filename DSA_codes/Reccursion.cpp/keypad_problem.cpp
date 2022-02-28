#include <bits/stdc++.h>
using namespace std;

void print(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<"    ";
    }
    cout<<endl;
}

void solve(string in, string out, int index, vector<string>& x, string map[])
{
    if(index >= in.length())
    {
        // cout<<out<<endl;
        x.push_back(out);
        return;
    }
    int z = in[index] - '0'; // for converting char into int.
    string p = map[z];
    for(int i = 0; i <p.length(); i++)
    {
        out.push_back(p[i]);
        solve(in, out, index+1, x, map); // here we are sending it for next index to be copied in "out" .
        out.pop_back();
    }
    
}

int main()
{
    string in;
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string out;
    vector<string> x;
    for (int i = 0; i < 2; i++)
    {
        char c;
        cin>>c;
        in.push_back(c);
    }
    solve(in, out, 0, x, map);
    print(x);
     
    return 0;
}