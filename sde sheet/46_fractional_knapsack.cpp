#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool comp(pii a, pii b)
{
    double r1 = (double)a.second/(double)a.first;
    double r2 = (double)b.second/(double)b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);
    double sack=0.0;
    for(int i=0; i<n&&w>0; i++)
    {
        double wt = items[i].first; 
        double val = items[i].second; 
        if(w-wt>=0)
        {
            w-=wt;
            sack+=val;
        }
        else
        {
            sack+=((double)val/(double)wt)*(double)w;
            w=0;
        } 
    }

    return sack;    
}

int main()
{
    vp items = {{50, 40}, {40, 50}, {90, 25}, {120, 100}, {10, 30}, {200, 45}};
    int wt = 200;
    int n =6;
    maximumValue(items, n, wt);
    return 0;
}