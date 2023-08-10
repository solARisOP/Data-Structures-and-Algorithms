#include <iostream>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// Stack class.
class Stack {
    int * arr;
    int last;
    int limit;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        last = -1;
        limit = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(!isFull())arr[++last] = num;
    }

    int pop() {
        // Write your code here.
        if(last>=0) return arr[last--];
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(last >=0) return arr[last];
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(last==-1) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(last+1 == limit) return 1;
        return 0;
    }
    
};


int main()
{
    
    return 0;
}