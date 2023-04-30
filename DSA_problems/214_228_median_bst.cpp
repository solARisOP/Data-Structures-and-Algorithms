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

void count_nodes(Node *root, int &count)
{
    if (!root) return;
    
    count++;
    count_nodes(root->left, count);
    count_nodes(root->right, count);
}

void median(Node * root, int  fl, float &prev, float &ans, int count, int& k)
{
    if(!root || ans != -1) return;

    median(root->left, fl, prev, ans, count, k);

    k++;
    if(!fl &&k == (count/2)+1)
    {
        ans = (prev+float(root->data))/2;
        return;
    }
    else if(fl && k == (count/2)+1)
    {
        ans = root->data;
        return;
    }
    prev = root->data;

    median(root->right, fl, prev, ans, count, k);
}


float findMedian(struct Node *root)
{
    //Code here
    int count = 0;  
    count_nodes(root, count);  
    int k = 0, fl=0;
    float ans = -1, prev = -1;
    if(count%2 ==0)
    {
        fl =0;
        median(root, fl, prev, ans, count, k);
        
    }
    else
    {
        fl =1;
        median(root, fl, prev, ans, count, k);
    }
    
    return ans;
      
}

int main()
{
    
    return 0;
}