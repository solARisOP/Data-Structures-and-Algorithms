#include <bits/stdc++.h>
using namespace std;

vector<string> teen = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
vector<string> ones = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
vector<string> Tens = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};

string word_call(int n)
{
    string ans = "";

    if(n/100)
    {
        ans+=ones[n/1e2]+" Hundred";
        n%=(long long)1e2;
    }

    if(n/10)
    {
        if(n/10 == 1)
        {
            ans+=teen[n%(long long)1e1];
            return ans;
        }

        ans+=Tens[n/1e1];
        n%=(long long)1e1;
    }

    if(n)
    {
        ans+=ones[n];
    }

    return ans;
}

string numberToWords(unsigned long long n)
{
    if(n<=0) return "Zero";
    string ans = "";
    if(n/1000000000000)
    {
        ans+=word_call(n/(unsigned long long)1e12)+" Trillion";
        n%=(unsigned long long)1e12;
    }

    if(n/1000000000)
    {
        ans+=word_call(n/1e9)+" Billion";
        n%=(long long)1e9;
    }

    if(n/1000000)
    {
        ans+=word_call(n/1e6)+" Million";
        n%=(long long)1e6;
    }

    if(n/1000)
    {
        ans+=word_call(n/1e3)+" Thousand";
        n%=(long long)1e3;
    }

    if(n)
    {
        ans+=word_call(n);
    }

    ans.erase(0,1);
    return ans;
}

int main()
{
    cout<<numberToWords(109345323454323);
    return 0;
}