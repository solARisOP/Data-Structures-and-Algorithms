/*
operators :-
-> AND (&) - any 0 than 0, all 1 than 1 : (a & b)
-> OR (|) - any 1 than 1, all 0 than 0 : (a | b)
-> XOR (^) - even 1 than 0, odd 1 than 1 : (a ^ b)
-> NEGATION (~) - 1 becomes 0 , 0 becomes 1 : (~a)
-> RIGHT SHIFT (>>) - the parameter which is on the right of the operator that many bits are gonna go off from the right of the number : (a >> 3)
-> lEFT SHIFT (<<) - the parameter which is on the right of the operator that many bits are gonna go off from the left of the number : (a << 3)
*/

#include <bits/stdc++.h>
using namespace std;
// XOR of two same numbers is 0 and XOR of 0 and a number is the number it self

int XOR_N(int N)
{
    // given number N print the XOR from 1 - N
    // O(1) solution
    int N;
    cin>>N;

    if(N % 4 == 1) cout<<1;
    if(N % 4 == 2) cout<<N+1;
    if(N % 4 == 3) cout<<0;
    if(N % 4 == 0) cout<<N;
}

int main()
{
    // swap to numbers
    int a =5, b =7;
    a = a^b;
    b = a^b; 
    a = a^b;

    cout<<a<<"  "<<b; 

    // given a range L - R , print the XOR from L to R
    int L,R;
    cin>>L>>R;

    cout<<(XOR_N(R) ^ XOR_N(L-1));

    // given two numbers N and i, find if the i'th bit set(meaning is it 1) of N in the binary
    int n,i;
    cin>>n>>i;

    int mask = 1<<i;
    n&mask ? cout<<"set" : cout<<"not set";

    // given two numbers N and i, set the i'th bit of N in the binary

    cin>>n>>i;
    mask = 1<<i;
    n = n | mask;

    // given two numbers N and i, clear the i'th bit of N in the binary

    cin>>n>>i;
    mask = ~(1 << i);
    n = n & mask;

    // given a number n , clear the last set bit of that number

    cin>>n;
    n = (n & (n-1));

    // given a number n , check if it is the power of 2

    cin>>n;
    if(n&(n-1) == 0) cout<<"yes";

    // count number of set bits in a number n

    cin>>n;
    int cnt=0;

    while(n)
    {
        if(n&1 == 1) cnt++;
        n = n>>1;
    } 

    cout<<cnt;

    // optimal solutions

    cin>>n;

    while(n)
    {
        n = (n & (n-1)); // we are clearing the last set bit every time and taking its count
        cnt++;
    }

    cout<<cnt;

    return 0;
}