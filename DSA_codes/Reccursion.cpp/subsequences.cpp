#include <iostream>
#include <vector>
using namespace std;

void subsets(string in, string out, int i, vector<string>& x)
{
    if(i >= 3)
    {
        if(out.length() < 1)
        {
            return ;
        }
        cout<<out<<endl;
        x.push_back(out);
        return ;
    }

    // exclude 
    subsets(in, out, i+1, x);

    // include
    char element = in[i];
    out.push_back(element);
    subsets(in, out, i+1, x);
    return ;

}

int main()
{
    string s = "pqr";
    string n;
    vector<string>x;

    subsets(s, n, 0, x);

    return 0;
}