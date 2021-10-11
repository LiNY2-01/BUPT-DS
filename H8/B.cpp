#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+50;
int a[Maxn];
int n,key;
int lower_bound(int n,int key)
{
    int l=1,r=n,cnt=0;
    while(l<r)
    {
    int mid=(l+r)>>1;
    ++cnt;
    if(key<a[mid])
    r=mid-1;
    else if(key>a[mid])
    l=mid+1;
    else if(key==a[mid])
    return cnt;
    }
    return cnt;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cin>>key;
    cout<<lower_bound(n,key);
}