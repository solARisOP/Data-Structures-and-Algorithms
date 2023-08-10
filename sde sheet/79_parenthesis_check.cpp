#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isValid(string s)
{
    stack<char> st;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;

            else if (s[i] == ')')
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        i++;
    }

    return st.empty();
}

int main()
{
    cout << isValid("()");
    return 0;
}