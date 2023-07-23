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

bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{

    return 0;
}