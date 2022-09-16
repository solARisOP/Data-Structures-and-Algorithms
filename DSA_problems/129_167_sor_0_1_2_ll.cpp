#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};
Node *segregate(Node *head)
{
    vector<Node *> zero, one, two;
    for (Node *i = head; i != NULL; i = i->next)
    {
        if (i->data == 0)
            zero.push_back(i);
        else if (i->data == 1)
            one.push_back(i);
        else
            two.push_back(i);
    }

    Node *temp = new Node(-1);
    Node *ans = temp;

    for (int i = 0; i < zero.size(); i++)
    {
        temp->next = zero[i];
        temp = temp->next;
    }

    for (int i = 0; i < one.size(); i++)
    {
        temp->next = one[i];
        temp = temp->next;
    }

    for (int i = 0; i < two.size(); i++)
    {
        temp->next = two[i];
        temp = temp->next;
    }

    temp->next = NULL;
    return ans->next;
}

int main()
{

    return 0;
}