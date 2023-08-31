#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node
{
    Node *links[2];

public:
    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        int n = 32;
        Node *node = root;
        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int x)
    {
        int ans = 0;
        int n = 32;
        Node *node = root;
        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (node->containsKey(!bit))
            {
                ans |= (1 << i);
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
        }
        return ans;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie *trie = new Trie();
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        trie->insert(nums[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, trie->getMaxXor(nums[i]));
    }

    return ans;
}

int main()
{

    return 0;
}