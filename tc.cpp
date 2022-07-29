/*
Selection Sort	Ω(n^2)	   θ(n^2)	  O(n^2)       O(1)

Bubble Sort	    Ω(n)	   θ(n^2)     O(n^2)	   O(1)

Insertion Sort	Ω(n)	   θ(n^2)     O(n^2)	   O(1)

Heap Sort	Ω(n log(n))	θ(n log(n))	O(n log(n))	   O(1)

Quick Sort	Ω(n log(n))	θ(n log(n))	  O(n^2)	 O(log(n))

Merge Sort	Ω(n log(n))	θ(n log(n))	O(n log(n))	   O(n)

Count Sort	Ω(n +k)	     θ(n +k)	O(n +k)	       O(k)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{                                                                                                                                       
    string a = "00:45";
    int g = (a[0]-'0')*10;
    int f = a[1]-'0';
    if((g+f) < 12) cout<<"AM";
    else cout<<"PM";
    return 0;
}