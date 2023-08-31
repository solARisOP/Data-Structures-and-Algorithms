#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node{
    Node* links[26];

    public:
    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node * get(char ch)
    {
        return links[ch-'a'];
    }
    
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int n = s.length();
    int cnt=1;
    for(int i=0; i<n; i++)
    {
        Node * node = root;
        for(int j=i; j<n; j++)
        {
            if(!node->containsKey(s[j]))
            {
                node->put(s[j], new Node());
                cnt++;
            }

            node = node->get(s[j]);
        }
    }

    return cnt;
}

int main()
{
    
    return 0;
}