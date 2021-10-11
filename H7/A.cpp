#include<bits/stdc++.h>
using namespace std;
const int Maxn=2080;
int m;
vector<int >g[Maxn];
queue<int >q;
int vis[Maxn];
void dfs(int x)
{
    vis[x]=1;
    if(x!=0)
    printf(" %d",x);
    for(int i=0;i<g[x].size();i++)
    if(!vis[g[x][i]])
        vis[g[x][i]] = 1, dfs(g[x][i]);
}
void bfs(int o)
{
    q.push(o);
    vis[o]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        if(x!=0)
        printf(" %d",x);
        for(int i=0;i<g[x].size();i++)
        if(!vis[g[x][i]])
        q.push(g[x][i]),vis[g[x][i]]=1;
    }
}
int main()
{
    cin>>m;int x;
    for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
    {
    cin>>x;
    if(x)
    g[i].push_back(j);
    }
    printf("0");
    dfs(0);
    memset(vis,0,sizeof(vis));
    printf("\n0");
    bfs(0);
}