#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i=0; 

        while(i<n && s[i]==' ') i++;
        if(i == n) return 0;

        char sign = '+';
        if(s[i] == '+' || s[i] == '-')
        {
            sign = s[i];
            i++;
        }
        if(i==n) return 0;

        while(i<n && int(s[i]-'0') == 0) i++;
        if(i==n) return 0;
        
        string ans="";
        while(i<n && int(s[i]-'0') <= 9 && int(s[i]-'0') >= 0)
        {
            ans+=s[i];
            i++;
        }
        int size_ans = ans.length();
        if(!size_ans) return 0;

        i = size_ans-1;
        long long digi = 0;
        int fl=1;
        while(i>=0 && digi<=INT_MAX)
        {
            int x = int(ans[i]-'0');
            if(!x) digi+=0;
            if(size_ans-i-1 > 10)
            {
                fl=0;
                break;
            } 
            else digi+=(x*pow(10, size_ans - i-1));
            i--;
        }

        if(!fl || digi>INT_MAX)
        {
            if(sign == '+') return INT_MAX;
            return INT_MIN;
        }

        if(sign == '+') return digi;
        
        return (-1)*digi;
    }
};

int main()
{
    
    return 0;
}