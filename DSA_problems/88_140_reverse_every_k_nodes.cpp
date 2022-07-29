#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node *next;
};

node *reverse(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int cnt = 1;
    node *p = NULL;
    node *n = NULL;
    node *c = head;

    while (c != NULL && cnt < k + 1)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        cnt++;
    }

    head->next = reverse(n, k);

    return p;
}

int main()
{

    return 0;
}