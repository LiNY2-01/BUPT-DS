#include<bits/stdc++.h>
using namespace std;
queue<int>q;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int n,x;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        x=read();
        q.push(x);
    }
    printf("%d %d %d %d",q.size(),q.front(),q.front(),q.size()-1);
}