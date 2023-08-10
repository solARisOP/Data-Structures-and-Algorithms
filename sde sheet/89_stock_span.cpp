#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {}
    
    int next(int price) {

        int span = 1;
        while(!st.empty() && st.top().first <= price)
        {
            span+=st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};


int main()
{
    
    return 0;
}