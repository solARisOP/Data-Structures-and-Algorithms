#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class MyQueue
{
    stack<int> st, helper;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        st.push(x);
        if (st.size() == 1)
            helper.push(x);
    }

    int pop()
    {
        int ans = helper.top();
        helper.pop();
        while (st.size() != 1)
        {
            helper.push(st.top());
            st.pop();
        }
        st.pop();
        int x = -1;
        if (helper.size())
            x = helper.top();
        while (helper.size())
        {
            st.push(helper.top());
            helper.pop();
        }

        if (x != -1)
            helper.push(x);

        return ans;
    }

    int peek()
    {
        return helper.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{

    return 0;
}