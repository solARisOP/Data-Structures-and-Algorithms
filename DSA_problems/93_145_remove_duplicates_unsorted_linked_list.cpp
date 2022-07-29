#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *i = head;
    unordered_map<int, int> mp;
    mp[i->data]++;
    Node *prev = i;
    i = i->next;

    while (i != NULL)
    {
        if (!mp[i->data])
        {
            mp[i->data]++;
        }
        else
        {
            Node *ptr = i;
            prev->next = i->next;
            i = prev;
            delete (ptr);
        }
        prev = i;
        i = i->next;
    }

    return head;
}

int main()
{

    return 0;
}