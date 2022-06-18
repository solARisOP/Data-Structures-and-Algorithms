#include <iostream>
using namespace std;

void reverse(string& p, int i)
{
    if(i>=p.length()/2)
    {
        return;
    }
    int n = p.length(); // or take a j from the end as we took i from the start.
    swap(p.at(i), p.at(n-i-1));
    i++;
    return reverse(p, i);
}

int main()
{
    string p = "nitish";
    reverse(p, 0);
    cout<<p;
    return 0;
}