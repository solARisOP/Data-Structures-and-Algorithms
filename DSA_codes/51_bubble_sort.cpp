#include <iostream>
using namespace std;

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
    cout<<a[i]<<"   ";
    }
    cout<<endl;
    
}

void bubblesort(int a[], int n)
{
    int issorted = 0;
    for (int i = 0; i < n-1; i++) // this is for no. of passes
    {
        cout<<"checking for "<<i+1<<" pass"<<endl;
        issorted = 1;
        for (int j = 0; j < n-1-i; j++) // this is for no. of comparisions
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                issorted = 0; //if this if statement doesn't executes then this variable will remain 1 and the function will return as below
                //in short we are making this shorting algo adaptive. 
            }
        }
        if(issorted)
        {
            return;
        }   
    }  
}
 
int main()
{
    int a[] = {1,3,5,67,32,6,78,49,56,7};
    int n = sizeof(a)/sizeof(int);
    printarray(a, n);
    bubblesort(a,n);
    printarray(a, n);
    return 0;
}

