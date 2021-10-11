#include<bits/stdc++.h>
using namespace std;
string v[5000];
string pre,mid,ans;
int flag=1;
void get_lrd(string pre,string mid,int dep)
{
    if(pre.size()<=0){return;}
    if(pre.size()!=mid.size()){flag=0;return;}
    v[dep].push_back(pre[0]);
    int pos=mid.find(pre[0]);
    if(pos==-1){flag=0;return;}
    get_lrd(pre.substr(1,pos),mid.substr(0,pos),dep+1);
    get_lrd(pre.substr(pos+1),mid.substr(pos+1),dep+1);
    ans.push_back(pre[0]);
}
int main()
{
    cin>>pre>>mid;
    //cout<<pre<<endl<<mid;
    
    get_lrd(pre,mid,1);
    if (flag)
    {
        cout<<ans<<endl;
        //putchar('\n');
        for (int i = 1; v[i].length(); i++)
        cout << v[i];
    }
    else cout<<"error";
}