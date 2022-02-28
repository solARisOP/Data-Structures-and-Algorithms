#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i);
void buildheap(int arr[], int n);
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void insertnode(int arr[], int &n, int value)
{
    // int i = n;
    // arr[i] = value;
    // n++;

    // while (i > 0 && arr[(i - 1) / 2] < arr[i])
    // {
    //     swap(arr[(i - 1) / 2], arr[i]);
    //     i = (i - 1) / 2;
    // }
    arr[n] = value;
    // ++n;
    buildheap(arr, ++n);
}

void deletenode(int arr[], int &n)
{
    // int i = 0;
    // arr[i] = arr[--n];
    // int l = i * 2 + 1, r = i * 2 + 2;
    // while (i < n)
    // {
    //     if (arr[i] < arr[r] && arr[l] < arr[r] && (r < n))
    //     {
    //         swap(arr[i], arr[r]);
    //         i = r;
    //         l = i * 2 + 1;
    //         r = i * 2 + 2;
    //     }
    //     else if (arr[i] < arr[l] && arr[l] > arr[r] && (l < n))
    //     {
    //         swap(arr[i], arr[l]);
    //         i = l;
    //         l = i * 2 + 1;
    //         r = i * 2 + 2;
    //     }
    //     else
    //         return;
    // }
    arr[0] = arr[n-1];
    // n--;
    heapify(arr, --n, 0);
}

void heapify(int arr[], int n, int i)
{
    // cout<<n<<endl;
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildheap(int arr[], int n)
{
    cout<<n<<endl;
    for (int i = (n/2)-1; i >= 0 ; i--)
    {
        heapify(arr, n, i);
    }
}

void heapsort(int arr[], int n)
{
    buildheap(arr, n);
    for (int i = n-1; i > 0 ; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    
}

int main()
{
    int arr[] = {55, 50, 40, 45, 35, 30, 10}; // max heap - the root node is always maximum than its children
    // we start from i =1
    // parent of any child  = (i-1)/2
    // left child of a parent = i*2+1
    // right child of a parent = i*2 + 2
    // no. of leaf nodes in a
    int n = sizeof(arr) / sizeof(int);
    printarray(arr, n);
    insertnode(arr, n, 56);
    printarray(arr, n);
    // deletenode(arr, n);
    // printarray(arr, n);
    // buildheap(arr, n);
    // printarray(arr, n);
    // heapsort(arr, n);
    // printarray(arr, n);
    return 0;
}