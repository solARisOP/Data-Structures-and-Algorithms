#include <bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> s;
    for(int i =0; i<n1; i++)
    {
        if(binary_search(B, B+n2, A[i]) && binary_search(C, C+n3, A[i]))
        {
            if(!binary_search(s.begin(), s.end(),A[i])) s.push_back(A[i]);
        }
    }
    return s;
}

int main()
{
    int a[] = {1, 5, 10, 20, 40, 80}, b[] ={6, 7, 20, 80, 100}, c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(a)/sizeof(int), n2 = sizeof(b)/sizeof(int), n3 = sizeof(c)/sizeof(int);
    vector<int> s = commonElements(a,b,c,n1,n2,n3);
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<"   ";
    }
    
    return 0;
}