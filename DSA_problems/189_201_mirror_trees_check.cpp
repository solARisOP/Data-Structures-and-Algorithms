#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node() : data(0), left(NULL), right(NULL) {}
        Node(int x) : data(x), left(NULL), right(NULL) {}
        Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

int checkMirrorTree(int n, int e, int A[], int B[])
{
    // code here
    unordered_map<int, stack<int>> mp;

    for (int i = 0; i < 2 * e; i++)
    {
        mp[A[i]].push(A[i + 1]);
        i++;
    }

    for (int i = 0; i < 2 * e; i++)
    {
        if (mp[B[i]].top() != B[i + 1])
            return 0;
        mp[B[i]].pop();
        i++;
    }

    return 1;
}

int main()
{

    return 0;
}