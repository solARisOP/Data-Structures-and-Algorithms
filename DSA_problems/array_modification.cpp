#include <iostream>
using namespace std;

void printarray(int a[], int n)
{
    cout<<"[";
    for (int j = 0; j < n; j++)
    {
        cout<<a[j]<<"   ";
    }
    cout<<"]";
    cout<<endl;
}

void convert(int a[], int n)
{
    int i = n-1;
    a[i] +=1;
    while(i>=0 && a[i] == 10)
    {
        a[i] =0;
        a[i-1] += 1;
        i--;
    }    
}

int main()
{
    int a[] = {9,9,9};
    int n = sizeof(a)/sizeof(int);

    printarray(a, n);
    convert(a, n);
    printarray(a, n);

    return 0;
}