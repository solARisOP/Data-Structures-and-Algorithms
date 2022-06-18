#include <bits/stdc++.h>
using namespace std;

int next_s(int s, string &str, char c)
{
    for (int i = s+1; i < str.size(); i++)
    {
        if(str[i]!= c) return str[i];
    }
    return -1;
}

bool rearrange_str(string &str)
{
    int s = str.size();
    int i = 0;
    while(i<s-1)
    {
        if(str[i] == str[i+1])
        {
            if(next_s(i+1, str, str[i+1])!= -1) swap(str[i+1], str[next_s(i+1, str, str[i+1])]);
            else return 0;
        }
        i++;
    }

    return 1;    
}

int main() 
{
	int T;
	cin >> T;
	while(T--)
	{
	    string str;
	    cin >> str;

        cout<<rearrange_str(str)<<endl;	    
	}
	return 0;
}