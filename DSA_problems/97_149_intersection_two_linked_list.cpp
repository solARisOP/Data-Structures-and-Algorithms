#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    // Node * ans = new Node;
    unordered_map<int , bool> mp;
    Node *c = head1;
    
    while(c != NULL)
    {
        mp[c->data] = true;
    }
    
    c= head2;
    
    Node *a;
    while(c!= NULL)
    {
        if(mp[c->data])
        {
            a = new Node(c->data);
            break;
        }
        c = c->next;
    }
    
    Node * ptr = a;
    while(c!= NULL)
    {
        if(mp[c->data])
        {
            Node * b = new Node(c->data);
            a->next = b;
            a = b;
        }
        c = c->next;
    }
    
    // a->next = NULL;
    
    return ptr;
}

int main()
{
    
    return 0;
}