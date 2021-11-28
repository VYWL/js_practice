// https://www.acmicpc.net/problem/
//
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++)
        printf("%c__", s[i]);
    cout << s.back();
}

/*
    
*/