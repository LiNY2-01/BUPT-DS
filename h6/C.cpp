#include <bits/stdc++.h>
using namespace std;
const int Maxn=5050;
int fa[Maxn<<1];
int n;
int c[5050];
long long ans=0;
priority_queue< pair< int , int > , vector< pair<int,int > > 
               ,greater<pair<int,int > > >pq;
int main()
{
    cin>>n;
    memset(fa,-1,sizeof(fa));
    for(int i=1;i<=n;i++)
    cin>>c[i],pq.push(make_pair(c[i],i));
    for(int i=n+1;i<=(n<<1)-1;i++)
    {
        int x=pq.top().second;pq.pop();
        int y=pq.top().second;pq.pop();
        fa[x]=i;fa[y]=i;
        pq.push(make_pair(c[x]+c[y],i));
    }
    for(int i=1;i<=n;i++)
    {   
        int res=0,x=i;
        while(fa[x]!=-1)
        x=fa[x],res++;
        ans+=1LL*res*c[i];
    }
    cout<<ans;

}