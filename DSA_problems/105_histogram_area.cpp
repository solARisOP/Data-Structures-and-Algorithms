#include <bits/stdc++.h>
using namespace std;

int areaofhistogram(vector<int> &h)
{
    int n = h.size();
    stack<int> st;
    vector<int> rs(n), ls(n); // these are for keeping left smaller and right smaller indexes for a particular index

    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && h[st.top()] >= h[i]) st.pop(); // if there is an element in the stack which is greater we remove it 

        if(st.empty()) ls[i] = 0; // if the stack is empty means the left small for this particular index is the starting index 0 itself
        else ls[i] = st.top()+1; // if the stack is not empty and the pop operrations have been over means we have got our left smallest boundary which is the top most element in the stack so we add a plus 1 to its index and store it 

        st.push(i); // we push that element index into stack
    }

    while(!st.empty()) st.pop();

    for (int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && h[st.top()] >= h[i]) st.pop();

        if(st.empty()) rs[i] = n-1;
        else rs[i] = st.top()-1;

        st.push(i);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (rs[i] - ls[i] +1)*h[i]); // it is a formula dervied for calculating histogram area the second parameter gives us the width of the particular rectangle with height h[i] and we multiple it with the particular index height to get the area
        // we keep track of maximum area then we return it below
    }
    
    return maxi;
}

int main()
{
    
    return 0;
}