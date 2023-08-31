#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node{
    Node* links[26];
    bool flag = false;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    } 
    
};

class Trie {
    private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        int n = word.length();
        for(int i=0; i<n; i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        int n = word.length();
        for(int i=0; i<n; i++)
        {
            if(!node->containsKey(word[i])) return false;

            node = node->get(word[i]);
            if(!node->isEnd()) return false;
        }

        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    sort(begin(a), end(a));
    Trie* trie = new Trie();

    for(int i=0; i<n; i++)
    {
        trie->insert(a[i]);
    }
    string ans = "";
    for(int i=0; i<n; i++)
    {
        if(trie->search(a[i]) && a[i].size()>ans.size()) ans = a[i];
    }

    return !ans.size() ? "None" : ans;
}

int main()
{
    
    return 0;
}