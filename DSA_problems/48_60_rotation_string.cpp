#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2)
{
    string temp = s1 +s1;

    if(temp.find(s2)>=0 && temp.find(s2)<temp.length())
    {
        return true;
    }
    return false;
}

int main()
{
   string str1 = "nitish", str2 = "ntiish";
   if (areRotations(str1, str2))
     printf("Strings are rotations of each other");
   else
      printf("Strings are not rotations of each other");
   return 0;
}