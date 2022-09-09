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

void printlist(Node * n)
{
    while(n)
    {
        cout<<n->data<<"  ";
        n = n->next;
    }
    cout<<endl;
}

// approach by using unordered_map
Node* findIntersection(Node* head1, Node* head2)
{
    unordered_map<int , int> mp;
    Node *c = head1;
    
    while(c != NULL)
    {
        mp[c->data] = 1;
        c = c->next;
        
    }
    
    c= head2;
    
    Node *a ;
    Node *pre ;
    Node * ans ;
    int fl = 0;
    while(c!= NULL)
    {
        if((mp[c->data] == 1) && (fl == 0))
        {
            a = new Node(c->data);
            pre = a;
            fl =1;
            ans = a;
            c = c->next;
            continue;
        }
        if((mp[c->data] == 1) && (fl == 1))
        {
            a = new Node(c->data);
            pre->next = a;
            pre = a;
        }
        c = c->next;
    }
    
    return ans;
}

// two pointer approach
Node* find_Intersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node * t1 = head1;
    Node * t2 = head2;
    
    Node *d = new Node(-1);
    Node * ans = d;
    
    while(t1 && t2)
    {
        if(t1->data == t2->data)
        {
            ans->next = new Node(t1->data);
            ans = ans->next;
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->data < t2->data)
        {
            t1=t1->next;
        }
        else
        {
            t2 = t2->next;
        }
    }
    
    return d->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);
    // printlist(head);
    
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    // printlist(head2);

    printlist(findIntersection(head, head2));
    return 0;
}