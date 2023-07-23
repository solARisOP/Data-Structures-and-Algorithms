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
        Node *child;

        Node() : val(0), next(NULL) {}
        Node(int x) : val(x), next(NULL) {}
        Node(int x, Node *nxt) : val(x), next(nxt) {}
};

Node* merge(Node* head1, Node* head2)
{
	Node* dummy = new Node(-1);
	Node*head = dummy;

	while(head1 && head2)
	{
		if(head1->val < head2->val)
		{
			dummy->child = head1;
			dummy = head1;
			head1 = head1->child;
		}
		else
		{
			dummy->child = head2;
			dummy = head2;
			head2 = head2->child;
		}
	}
	while(head1)
	{
		dummy->child = head1;
		dummy = head1;
		head1 = head1->child;
	}

	while(head2)
	{
		dummy->child = head2;
		dummy = head2;
		head2 = head2->child;
	}

	head = head->child;
	return head;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head || !head->next) return head;
	Node * temp = head->next;
	Node* ans = head;
	while(temp)
	{
		ans = merge(ans, temp);
		temp = temp->next;
	}

	return ans;

}

int main()
{
    
    return 0;
}