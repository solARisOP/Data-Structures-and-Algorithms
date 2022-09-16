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

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (a && b)
    {
        if (a->data < b->data)
        {
            temp->next = a;
            temp = a;
            a = a->next;
        }

        else
        {
            temp->next = b;
            temp = b;
            b = b->next;
        }
    }

    while (a)
    {
        temp->next = a;
        temp = a;
        a = a->next;
    }

    while (b)
    {
        temp->next = b;
        temp = b;
        b = b->next;
    }
    ans = ans->next;
    return ans;
}

Node *mergeKLists(Node *arr[], int k)
{
    // Your code here
    if (k == 1)
        return arr[0];
    Node *temp = merge(arr[0], arr[1]);
    for (int i = 2; i < k; i++)
    {
        temp = merge(temp, arr[i]);
    }

    return temp;
}

int main()
{

    return 0;
}