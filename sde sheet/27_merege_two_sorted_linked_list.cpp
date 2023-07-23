#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node
{
public:
    int val;
    Node *next;

    Node() : val(0), next(NULL) {}
    Node(int x) : val(x), next(NULL) {}
    Node(int x, Node *nxt) : val(x), next(nxt) {}
};

Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *head = dummy;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            dummy->next = list1;
            dummy = list1;
            list1 = list1->next;
        }
        else
        {
            dummy->next = list2;
            dummy = list2;
            list2 = list2->next;
        }
    }

    while (list1)
    {
        dummy->next = list1;
        dummy = list1;
        list1 = list1->next;
    }

    while (list2)
    {
        dummy->next = list2;
        dummy = list2;
        list2 = list2->next;
    }

    return head->next;
}

int main()
{

    return 0;
}