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

int mod = 1e9 + 7;

long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    long long a = 0, b = 0;

    while (l1)
    {
        a = (a * 10 + l1->data) % mod;
        l1 = l1->next;
    }
    
    while (l2)
    {
        b = (b * 10 + l2->data) % mod;
        l2 = l2->next;
    }

    return (a * b) % mod;
}

int main()
{

    return 0;
}