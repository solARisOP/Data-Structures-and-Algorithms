#include <iostream>
using namespace std;

bool pallindrome(string& p, int i, int j)
{
    if (i>=j)
    {
        return true;
    }
    
    if(p.at(i) == p.at(j))
    {
        i++, j--;
        return pallindrome(p, i, j);
    }
    else
    {
        return false;
    }
}

int main()
{
    string p = "zayaz";
    if(pallindrome(p, 0, p.length()-1))
    {
        cout<<"It is a pallindrome"<<endl;
    }
    else
    {
        cout<<"Not a pallindrome"<<endl;
    }
    return 0;
}