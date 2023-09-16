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
    int val;
    Node *next;
    Node *random;

    Node() : val(0), next(NULL), random(NULL) {}
    Node(int x) : val(x), next(NULL), random(NULL) {}
    Node(int x, Node *nxt, Node *rnd) : val(x), next(nxt), random(rnd) {}
};


// recursion O(N) space
Node *solve(Node *curr, unordered_map<Node *, Node *> &mpp)
{
    if (!curr)
        return NULL;

    if (mpp.find(curr) == mpp.end())
        mpp[curr] = new Node(curr->val);

    if (curr->random)
    {
        if (mpp.find(curr->random) == mpp.end())
            mpp[curr->random] = new Node(curr->random->val);
        mpp[curr]->random = mpp[curr->random];
    }
    else
        mpp[curr]->random = NULL;

    mpp[curr]->next = solve(curr->next, mpp);
    return mpp[curr];
}
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mpp;
    return solve(head, mpp);
}

// iterative O(1) space
Node* copyRandomList(Node* head) {
        
        Node* curr=head;
        
        while(curr)
        {
            Node* newNode= new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
            
        }

        curr = head;
        while(curr)
        {
            if(curr->random)curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node* dummy = new Node(-1);
        Node* ans = dummy;
        curr = head;
        while(curr)
        {
            Node* temp = curr ->next;
            ans->next = temp;
            curr->next = temp->next;
            curr = curr->next;
            ans = ans->next;
        }

        return dummy->next;
    }

int main()
{

    return 0;
}