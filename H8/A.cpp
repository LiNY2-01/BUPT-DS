#include<bits/stdc++.h>
using namespace std;
const int Maxn=5050;
struct node
{
    int data,lson,rson;
}t[Maxn];
int a[Maxn];
int n,cnt=1;
int d[3];
int insnode(int x,int data)
{
    if(x==-1){t[++cnt]={data,-1,-1};return cnt;}
    if(data<t[x].data)t[x].lson=insnode(t[x].lson,data);
    else t[x].rson=insnode(t[x].rson,data);
    return x;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    t[1]={a[1],-1,-1};
    for(int i=2;i<=n;i++)
    insnode(1,a[i]);
    int cd=0;
    for(int i=1;i<=n;i++)
    {
        cd=0;
        if(~t[i].lson)cd++;
        if(~t[i].rson)cd++;
        d[cd]++;
    }
    printf("%d %d %d",d[0],d[1],d[2]);
}