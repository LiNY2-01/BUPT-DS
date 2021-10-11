#include<bits/stdc++.h>
using namespace std;
char s[1050];
#define lson(x) ((x<<1)  )
#define rson(x) ((x<<1)|1)
int n ;
void pre(int x)
{
    if(x>n)return;
    if(s[x]!='0')
    putchar(s[x]);
    else return;
    //int mid=(r-l+1)>>1;
    pre(lson(x));
    pre(rson(x));
}
int main()
{
    cin>>(s+1);
    n=strlen(s+1);
    pre(1);
    putchar('\n');
    for(int i=1;i<=n;i++)
    if(s[i]!='0')
    putchar(s[i]);
    
    return 0;
}