#include <bits/stdc++.h>
using namespace std;

int minFlips (string S)
{
    int f = 0, s = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if(i%2 == 0) 
            if(S[i] != '1')
            {
                f++;
            }
        else
            if(S[i] != '0')
            {
                f++;
            }
    }
    for (int i = 0; i < S.length(); i++)
    {
        if(i%2 == 0) 
            if(S[i] != '0')
            {
                s++;
            }
        else
            if(S[i] != '1')
            {
                s++;
            }
    }
    
    return min(f,s);
}
//better approach
// int minFlips (string S)
// {
//     int fir=0,sec=0;

//         for(int i=0;i<S.length();i++){
//             if((i%2==0 && S.at(i)=='1')||(i%2!=0 && S.at(i)=='0'))fir++;
//             else sec++;
//         }
        
//         return min(fir,sec);
//     // your code here
// }
int main()
{
    
    return 0;
}