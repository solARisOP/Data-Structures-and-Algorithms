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
void printlist(Node *n)
{
    while (n)
    {
        cout << n->data << "  ";
        n = n->next;
    }
    cout << endl;
}



int main()
{
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    printlist(mergeSort(head));

    return 0;
}