#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+10;
typedef long long ll;
ll  n,a[Maxn],r[Maxn];
ll d[Maxn];
ll ans[Maxn];
ll k;
int flag=0;
void printans()
{
	if(flag)
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<(i==n?"":" ");
	else 
	for(int i=1;i<=n;i++)
	cout<<a[i]<<(i==n?"":" ");
	flag=0;
	putchar('\n');

}
void cpdata()
{
	for(int i=1;i<=n;i++)
	a[i]=d[i];
}
void qsort(int l,int r,int dep)
{
	if(l>=r)return ;
	int i=l,j=r,mid,p;
	mid=a[l];
	while(i<j)
	{
		while(i<j&&a[j]>=mid)j--;
		a[i]=a[j];
		while(i<j&&a[i]<=mid)i++;
		a[j]=a[i];
	}
	a[i]=mid;
    if (dep == k)
	{
		flag=1;
    for (int i = l; i <= r; i++)
            ans[i] = a[i];
	}
    qsort(l,i-1,dep+1);
	qsort(i+1,r,dep+1);
}

void msort(int s,int t,int dep)
{
	if(s==t)
	{
	if(dep==k)
	{
		flag = 1;
	for (int i = s; i <= t; i++)
		ans[i] = a[i];
	}
	return;
	}
	int mid=(s+t)/2,i=s,j=mid+1,c=s;
	msort(s,mid,dep-1);msort(mid+1,t,dep-1);
	while(i<=mid&&j<=t)
	{
		if(a[i]<=a[j])
		{r[c]=a[i];c++;i++;}
		else
		{r[c]=a[j];j++;c++;}
	}
	while(i<=mid)
	{r[c]=a[i];i++;c++;}
	while(j<=t)
	{r[c]=a[j];j++;c++;}
	
	for(int i=s;i<=t;i++)
	a[i]=r[i];

    if(dep==k)
	{
		flag = 1;
	for (int i = s; i <= t; i++)
		ans[i] = a[i];
	}
}
void bsort()
{
	for(int i=1;i<n;i++)
	{
	for(int j=1;j<=n-i;j++)
	if(a[j]>a[j+1])swap(a[j],a[j+1]);
	if(i==k)
	{
	for(int i=1;i<=n;i++)
	ans[i]=a[i];
	flag=1;
	}
	}
}
void isort()
{
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]>a[i])
		{
			a[0]=a[i];
			int j;
			for( j=i-1;a[0]<a[j];j--)
			a[j+1]=a[j];
			a[j+1]=a[0];
		}
		if(i==k+1)
		{
		for (int i = 1; i <= n; i++)
			ans[i] = a[i];
		flag=1;	
		}
	}
}
void ssort()
{
	for(int i=1;i<n;i++)
	{
		int minx=i;
		for(int j=i+1;j<=n;j++)
		if(a[j]<a[minx])
		minx=j;
		swap(a[minx],a[i]);
		if(i==k)
		{
			for (int i = 1; i <= n; i++)
				ans[i] = a[i];
			flag = 1;
		}
	}
}
void hsort()
{
	for(int d=n>>1,cnt=1;d>=1;d>>=1,cnt++)
	{
		for(int i=d+1;i<=n;i++)
		{
			if(a[i]<a[i-d])
			{
				int num=a[i];
				int j;
				for(j=i-d;j>0&&num<a[j];j-=d)
				a[j+d]=a[j];
				a[j+d]=num;
			}
		}

		if(cnt==k)
		{
			for (int i = 1; i <= n; i++)
				ans[i] = a[i];
			flag = 1;
		}
	}
}
void sift(int x,int len)
{
	int now=x,son=now<<1;
	while(son<=len)
	{
		if(son<len&&a[son]<a[son+1])son++;
		if(a[now]>a[son])break;
		swap(a[now],a[son]);
		now=son;
		son=now<<1;
	}
}
void heap_sort()
{
	for(int i=n>>1;i>=1;i--)
	sift(i,n);
	for(int i=n;i>1;i--)
	{
		swap(a[1],a[i]);
		
		if(k==n-i+1)
		{
			for (int i = 1; i <= n; i++)
				ans[i] = a[i];
			flag = 1;
		}
		sift(1, i - 1);
	}
}
int main()
{
	cin>>n>>k;
	int dep = 0;
	while ((1 << dep) < n)
		dep++;
	//cout<<dep<<endl;
	//cout<<ceil(log2(n))<<endl;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	cpdata();
	bsort();
	printans();

	cpdata();
	isort();
	printans();

	cpdata();
	ssort();
	printans();

	cpdata();
	hsort();
	printans();

	cpdata();
	qsort(1,n,1);
	printans();

	cpdata();
	heap_sort();
	printans();


	cpdata();
	
	msort(1,n,dep);
	printans();
	return 0;
}