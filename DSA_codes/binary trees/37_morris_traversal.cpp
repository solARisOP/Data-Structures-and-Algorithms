#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(NULL), right(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x, Node *a, Node *b) : val(x), left(a), right(b) {}
};


// curr is for traversing the orders and storing and prev is for making the connections
vi m_inorder(Node * root)
{
    Node * curr = root;
    vi inorder;
    while(curr)
    {
        if(!curr->left) // if left doent exist we we store and move to right
        {
            inorder.push_back(curr->val); // if we dont have a subtree in left then as per inorder we store the root
            curr = curr->right; // and we move to right
        }
        else // if exist then we make the connections as per morris traversals
        {                                                                                           
            Node * prev = curr->left;  // traversing the full left subtree to make connections;                                                                 
            while(prev->right && prev->right != curr) prev = prev->right;                                                                                          
                                                                                                                                                                 
            if(prev->right == NULL) // if it is NULL meaning we have not visited it yet                                                                                                                    
            {                                                                                                                                       
                prev->right = curr; // so we connect it with the root                                                                                       
                curr = curr->left; // and move curr forward                                                                                                                         
            }                                                                                                                                                   
            else // if it is not NULL meaning we have visited it                                                                                                                
            {                                                                                                                                                                   
                prev->right = NULL; // so we break the connection we made last time                                                                                     
                inorder.push_back(curr->val); // so the left subtree is visited so as per inorder we store the root
                curr = curr->right; // and as the left subtree is visited me move to right
            }
        }
    }

    return inorder;
}

vi m_preorder(Node * root)
{
    Node * curr = root;
    vi preorder;
    while(curr)
    {
        if(!curr->left) // if left doent exist we store and move to right
        {
            preorder.push_back(curr->val); // we store the root as per preorder
            curr = curr->right; // and then if we dont have a subtree in left we move to right
        }
        else // if exist then we make the connections as per morris traversals
        {                                                                                           
            Node * prev = curr->left;  // traversing the full left subtree to make connections;                                                                 
            while(prev->right && prev->right != curr) prev = prev->right;                                                                                          
                                                                                                                                                                 
            if(prev->right == NULL) // if it is NULL meaning we have not visited it yet                                                                                                                    
            {                                                                                                                                       
                prev->right = curr; // so we connect it with the root
                preorder.push_back(curr->val); // so before visiting the left subtree with curr as per preorder we store the root                                                                                      
                curr = curr->left; // and move curr left                                                                                                                        
            }                                                                                                                                                   
            else // if it is not NULL meaning we have visited it                                                                                                                
            {                                                                                                                                                                   
                prev->right = NULL; // so we break the connection we made last time                                                                                     
                curr = curr->right; // and as the left subtree is visited and we came back to root meaning we have already stored the root as per preorder so me move to right
            }
        }
    }

    return preorder;
}


int main()
{
    
    return 0;
}