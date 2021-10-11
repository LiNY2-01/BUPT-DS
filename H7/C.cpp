#include <bits/stdc++.h>
using namespace std;
const int Maxm=2e5+50;
const int Maxn=1060;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct edge
{int to,w,c,next;}e[Maxm];int last[Maxn],cnt=0,vis[Maxn];
inline void addedge(int u,int v,int w,int c)
{e[++cnt]={v,w,c,last[u]};last[u]=cnt;}
ll d[Maxn],c[Maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>,
               greater<pair<int, int>>> q;
int n=1,m=1;
void djj(int s)
{
    memset(d, INF, sizeof(d));

    d[s] = 0;
    c[s]=0;
    q.push(make_pair(0, s));
    while (!q.empty())
    {
        int now = q.top().second;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (int i = last[now]; i; i = e[i].next)
        {
            if (d[now] + e[i].w < d[e[i].to])
                d[e[i].to] = d[now] + e[i].w, q.push(make_pair(d[e[i].to], e[i].to)),
                c[e[i].to] = c[now] + e[i].c;
            else if (d[now] + e[i].w == d[e[i].to])
            {
                c[e[i].to] = min(c[now] + e[i].c,c[e[i].to]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while(m!=0||n!=0)
    {
        cnt=0;
        for(int i=1;i<=m;i++)
        {
            int u, v, w, x;
            cin>>u>>v>>w>>x;
            addedge(u,v,w,x);
            addedge(u,v,w,x);
        }
        int u,v;
        cin>>u>>v;
        djj(u);
        cout<<d[v]<<" "<<c[v]<<endl;
        cin >> n >> m;
    }
}