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

void selectionsort(int *a, int n)
{
    int index;
    for (int i = 0; i < n-1; i++)
    {
        index = i;
        for (int j = i+1; j < n  ; j++)
        {
            if (a[j]<a[index])
            {
                index =j;
            }
            
        }
        swap(a[i], a[index]);  
    }
}

// Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


int main()
{
    int a[] = {1,3,5,67,32,6,78,49,56,7};
    int n = sizeof(a)/sizeof(int);
    // printarray(a, n);
    selectionsort(a, n);
    printarray(a, n);
    return 0;
}