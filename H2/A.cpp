#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6+50;
const int hh=1e6;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int a[Maxn],nxt[Maxn];
int head,n,k;
int main()
{
    cin>>head>>n>>k;
    int p,val,nxxt;
    for(int i=1;i<=n;i++)
    {
        p=read(),val=read(),nxxt=read();
        a[p]=val,nxt[p]=nxxt;
    }
    n=1;
    p=head;
    while(p!=-1)
    {
        p=nxt[p];
        n++;
    }
    a[hh]=0,nxt[hh]=head;
    p=head;int dum_head=hh;
    int x;
    for(int i=0;i<n&&n-i>=k;i++)
    {
        for(int j=1;j<k&&i<n;i++,j++)
        {
            x=nxt[p];
            nxt[p]=nxt[x];
            nxt[x]=nxt[dum_head];
            nxt[dum_head]=x;

        }
        dum_head=p;
        p=nxt[p];
    }
    p=nxt[hh];
    for(int i=1;i<=n;i++)
    {
    if(nxt[p]!=-1)
    printf("%05d %d %05d\n",p,a[p],nxt[p]);
    else
    printf("%05d %d -1\n", p, a[p]);
    p=nxt[p];
    }
    return 0;
}