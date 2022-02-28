#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<"    ";
    }
    cout<<endl;
}

void solve(string in, int index, vector<string>& x)
{
    if(index >= in.length())
    {
        x.push_back(in);
        return;
    }
    for (int j = index; j < in.length(); j++)
    {
        swap(in[index], in[j]);
        // cout<<"sending for string : "<<in<<endl;
        solve(in, index+1, x);
        // cout<<"came back"<<endl;
        swap(in[index], in[j]);
    }
    
}

int main()
{
    string in;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin>>c;
        in.push_back(c);
    }
    
    vector<string> x;
    solve(in, 0, x);
    print(x);



    return 0;
}