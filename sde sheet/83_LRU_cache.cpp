#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;

    Node() : key(0), val(0) , next(NULL), prev(NULL) {}
    Node(int k, int x) : key(k), val(x), next(NULL), prev(NULL) {}
    Node(int k, int x, Node *nxt, Node *prv) : key(k), val(x), next(nxt), prev(prv) {}
};

class LRUCache {
    int limit, i;
    unordered_map<int, Node*> mpp;
    Node *head;
    Node *tail;
public:
    LRUCache(int capacity) {
        limit = capacity;
        i=0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node*x = mpp[key]->prev;
        Node*y = mpp[key]->next;
        Node*ele = mpp[key];
        x->next = y;
        y->prev = x;
        i--;
        mpp.erase(ele->key);
        put(key, ele->val);
        return ele->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end())
        {
            mpp[key]->val = value;
            get(key);
        } 
        else
        {
            if(i == limit)
            {
                Node* x = tail->prev;
                x->prev->next = tail;
                tail->prev = x->prev;
                mpp.erase(x->key);
                delete(x);
                i--;
            }
            Node* x = head->next;
            Node* cache = new Node(key, value);
            cache-> next = x;
            x->prev = cache;
            head->next = cache;
            cache -> prev = head;
            mpp[key] = cache; 
            i++;
        }

    }
};

int main()
{
    
    return 0;
}