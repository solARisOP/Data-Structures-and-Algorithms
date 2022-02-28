#include <iostream>
using namespace std;

class queue
{
    public:
        int size;
        int f;
        int r;
        int *arr;
};

queue *q = new queue();

int isfull()
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}

int isempty()
{
    if(q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(int val)
{
    if(isfull())
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // cout<<"enqueued : "<<val<<endl;
    }
}

int dequeue()
{
    int a = -1;
    if(isempty())
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    q->f = q->r = -1;
    q->size = 100;
    q->arr = new int[q->size];
    int i = 3; // we are choosing a node to start.
    int visited[6] = {0,0,0,0,0,0};// we are keeping track of the visited nodes and marked them initially 0 as we have not visited any of them yet.

    int a[6][6] = { 
        {0,1,1,0,1,0},
        {1,0,1,0,0,0},         // this 2d array or matrix is a adjacent matrix represtation of the graph.
        {1,1,0,1,0,1},         // 1 means connected, 0 means not connected.
        {0,0,1,0,0,1},
        {1,0,0,0,0,1},
        {0,0,1,1,1,0}
    };
    cout<<i; // we are printing the visited node.
    visited[i] = 1;  // i represents the particular node, we are marking it as visited.
    enqueue(i); // we have enqueued the particular node (i) for exploration. 
    while(!isempty()) // if the queue becomes empty at any point meaning we have explored all nodes thus it will exit the while loop.
    {
        int n = dequeue(); // we dequeue the node for exploration which means visiting its connected nodes, as in below. 

        for (int j = 0; j < 6; j++)
        {
            if(a[n][j] == 1 && visited[j] == 0)// here we are checking if the nodes are connected or not and if we visited it or not.
            {
                cout<<j; // we are printing the visited node.
                visited[j] = 1; // we are marking it as visited. 
                enqueue(j); // and enqueued it.
            }
        }
        
    }
    
    return 0;
}