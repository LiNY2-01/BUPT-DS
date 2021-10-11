#include<bits/stdc++.h>
using namespace std;
const int Maxn=2050;
int sumx[Maxn];
int mulx[Maxn];
int ax[Maxn],ap[Maxn];
int bx[Maxn],bp[Maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int a,b;
    a=read();
    for(int i=1;i<=a;i++)
    ax[i]=read(),ap[i]=read(),sumx[ap[i]]+=ax[i];
    b=read();
    for(int i=1;i<=b;i++)
    bx[i]=read(),bp[i]=read(),sumx[bp[i]]+=bx[i];

    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++)
    mulx[ap[i]+bp[j]]+=ax[i]*bx[j];
    int flag=0;
    for(int i=2000;i>=0;i--)
    if(mulx[i]){
        if(flag)printf(" %d %d",mulx[i],i);
        else printf("%d %d",mulx[i],i),flag=1;
    }
    if(!flag)
    cout<<"0 0"<<endl;
    else
    cout<<endl;
    flag=0;
    for(int i=2000;i>=0;i--)
    if(sumx[i]){
        if(flag)printf(" %d %d",sumx[i],i);
        else printf("%d %d",sumx[i],i),flag=1;
    }
    if(!flag)
    cout<<"0 0";
    return 0;
}