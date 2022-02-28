#include <iostream>
using namespace std;

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

int merge(int a[], int low, int mid, int high)
{
    int b[100], p= 0;
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++, k++;
        }
        else
        {
            b[k] = a[j];
            j++, k++;
            p+=mid -i; //because left and right subarrays are sorted,
                       // so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++, k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++, k++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
    return p;
}

int mergesort(int a[], int low, int high)
{
    int mid, q =0;
    if (low < high)
    {
        mid = (low + high) / 2;
        q += mergesort(a, low, mid);
        q += mergesort(a, mid + 1, high);
        q += merge(a, low, mid, high);
    }
    return q;
}

int main()
{
    int a[] = {468 ,335, 1, 170 ,225 ,479 ,359 ,463 ,465 ,206 ,146 ,282 ,328 ,462 ,492 ,496 ,443 ,328 ,437 ,392 ,105 ,403 ,154 ,293 ,383 ,422 ,217 ,219 ,396 ,448 ,227 ,272 ,39 ,370 ,413 ,168 ,300 ,36, 395 ,204 ,312, 323};
    int n = sizeof(a) / sizeof(int);
    cout<<mergesort(a, 0, n - 1)<<endl;
    return 0;
}