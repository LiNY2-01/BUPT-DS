#include<bits/stdc++.h>
using namespace std;
const int Maxn=150,Maxm=1e4+50;
int fa[Maxn];
struct edge
{int u,v,w;}e[Maxm];int ecnt=0;
bool cmp(edge x,edge y){return x.w<y.w;}
int n;
int find(int x)
{return fa[x]==x?x:(fa[x]=find(fa[x]));}
int main()
{
    cin>>n;
    int x;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>x;
        if(x)
        e[++ecnt]={i,j,x};
    }
    sort(e+1,e+1+ecnt,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    int cnt=0;
    long long ans=0;
    for(int i=1;i<=ecnt&&cnt!=n-1;i++)
    {
        int a,b;
        a=e[i].u,b=e[i].v;
        if(find(a)!=find(b))
        ans+=e[i].w,++cnt,fa[b]=find(a);
    }
    cout<<ans;
}