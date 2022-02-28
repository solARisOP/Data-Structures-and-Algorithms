#include <iostream>
using namespace std;

bool linearsearch(int arr[], int size, int key)
{
    if(size == 0)
    {
        return false;
    }
    if(arr[0] == key)
    {
        return true;
    }
    return linearsearch(arr+1, size - 1, key);
}

int main()
{
    int arr[10] = {2, 5, 14, 19, 23, 39, 42, 48, 51, 56};
    int size = 10;
    if(linearsearch(arr, size, 51))
    {
        cout<<"element found"<<endl;
    }
    else
    {
        cout<<"element not found"<<endl;
    }
    return 0;
}