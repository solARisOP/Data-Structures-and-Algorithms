#include <bits/stdc++.h>
using namespace std;

void searchf(string pat, string txt)
{
    if(pat.substr(0, txt.length()) == txt)
    {
        cout<<"0"<<" ";
    }
    int i =1;
    while(i+txt.length()-1<pat.length())
    {
        if (pat.find(txt, i)!=string :: npos)
        {
            cout<<pat.find(txt, i)<<" ";
            i = pat.find(txt, i) +1;
        }
        else break;
    }
}

int main()
{
    string pat = "AABAACAADAABAABA";
    string txt = "AABA";
    searchf(pat, txt);
    return 0;
}