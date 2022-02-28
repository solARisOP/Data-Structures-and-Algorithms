#include <iostream>
using namespace std;

void print(int a)
{
    if( a == 0)
    {
        return;
    }
    // print(a-1); // --> if we write this recursive relation(head recursion) here then aur numbers will be printed from 1 upto a.
    cout<<a<<"  ";
    print(a-1);
}

int main()
{
    int a;
    cin>>a;
    print(a);
    return 0;
}