#include<bits/stdc++.h>
using namespace std;
string a[602];
int main()
{
    int cnt=0;
    while(cin>>a[++cnt]);
    //cout<<cnt<<endl;
    //cout<<a[cnt]<<endl;
    while(--cnt)
    {
        cout<<a[cnt];
        if(cnt!=1)cout<<" ";
    }
    return 0;
}