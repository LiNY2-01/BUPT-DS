#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+50;
int top=0;
int main()
{
    char ch;int flag=1;
    while((ch=getchar())!=EOF)
    {
        if(ch=='(')
        top++;
        else if(ch==')')
        top--;
        if(top<0)
        flag=0;
    }
    if(top!=0)
    flag=0;
    cout << (flag ? "OK" : "Error");
}