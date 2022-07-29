#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

int main()
{
    cout<<"nitish";
    gotoxy(35, 14);
    return 0;
}