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

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
    int qs = queries.size();

    vector<pair<int, pii>> offlineQueries;

    int x = 0;
    for (vi it : queries)
    {
        offlineQueries.push_back({it[1], {it[0], x++}});
    }
    sort(begin(nums), end(nums));
    sort(begin(offlineQueries), end(offlineQueries));

    vi ans(qs, -1);
    Trie *trie = new Trie();

    int i = 0, n = nums.size();

    for (auto it : offlineQueries)
    {
        while (i < n && nums[i] <= it.first)
            trie->insert(nums[i++]);
        if (i)
            ans[it.second.second] = trie->getMaxXor(it.second.first);
    }

    return ans;
}

int main()
{

    return 0;
}