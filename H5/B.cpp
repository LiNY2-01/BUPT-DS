#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+50;
int f[Maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int n,s;
int main()
{
    s=read(),n=read();
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        int w=read();
        for(int j=s;j>=w;j--)
        {
            f[j]=f[j]+f[j-w];
        }
    }
    cout<<f[s]<<endl;
}