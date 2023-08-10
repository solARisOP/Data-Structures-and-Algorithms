#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(!st.empty()) st.push({val, min(st.top().second, val)});
        else st.push({val, val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main()
{
    
    return 0;
}