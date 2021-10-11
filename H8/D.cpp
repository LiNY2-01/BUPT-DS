#include<bits/stdc++.h>
using namespace std;
int n,m,mod;
int key;
int a[100050];
void ins(int x)
{
    int add=x%mod;
    while(a[add])add=(add+1)%m;
    a[add]=x;
}
int find(int x)
{
    int cnt=0;
    int add=x%mod;
    //if(!a[add])return 0;
    while(a[add])
    {
        cnt++;
        if(a[add]==x)return cnt;
        add=(add+1)%m;
    }
    return cnt;
}
int main()
{
    cin>>n>>mod>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ins(x);
    }
    cin>>key;
    cout<<find(key);
}