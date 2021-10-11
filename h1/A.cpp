#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int x,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans^=x;
    }
    int *p=new int ;
    *p=ans;
    cout<<*p;
}