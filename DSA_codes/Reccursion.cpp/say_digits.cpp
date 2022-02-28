#include <iostream>
using namespace std;

void saydigits(int n, string arr[])
{
    if(n == 0)
    {
        return;
    }
    int digit = n%10;
    n = n/10;
    saydigits(n, arr);
    cout<<arr[digit]<<" "; 
    // saydigits(n, arr); // if we put this here then it will print digits in opposite direction.
}

int main()
{
    int a;
    cin>>a;
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    saydigits(a, arr);
    return 0;
}