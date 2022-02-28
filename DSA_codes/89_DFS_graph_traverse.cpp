#include <iostream>
using namespace std;

int visited[6] = {0,0,0,0,0,0}; // we are keeping track of the visited nodes and marked them initially 0 as we have not visited any of them yet.

int a[6][6] = { 
    {1,0,1,0,0,0},         
    {0,1,1,0,1,0}, // this 2d array or matrix is a adjacent matrix represtation of the graph.
    {1,1,0,1,0,1}, // 1 means connected, 0 means not connected.        
    {0,0,1,0,0,1},
    {1,0,0,0,0,1},
    {0,0,1,1,1,0}
};

// making the above two variables as global as we can access them from any function.

void DFS(int i)
{
    cout<<i; // we are printing the visited node.  
    visited[i] = 1; // i represents the particular node, we are marking it as visited.
    // The above two lines are a type of base condition for this recussive function,
    // and as this is a void function we do not need to return anything.

    for (int j = 0; j < 6; j++)
    {
        if (a[i][j] == 1 && !visited[j]) // here we are checking if the nodes are connected or not and if we visited it or not.
        {
            DFS(j); // we are calling the function for the connected node.
        }
        
    }
    
}

int main()
{
    DFS(0); //we are sending a node from which we want to start our DFS, it can be any node.
    return 0;
}