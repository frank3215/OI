#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+4,maxm=50000+4,maxq=30000+4;
int n,m,q;
int fa[maxn],ans[maxq];
set<int> ask[maxn];
struct node
{
	int fr,to,val;
	bool operator < (const node &x) const
	{return val>x.val;}
}a[maxm];
int find(int x) {return fa[x] = (x==fa[x]) ? x : find(fa[x]);}
void link(int x,int y,int v)
{
	set<int>::iterator i;
	for(i=ask[y].begin();i!=ask[y].end();i++)
	{
		if(ask[x].find(*i)!=ask[x].end()) ans[*i]=v;
		else ask[x].insert(*i);
	}
}
void merge(int x,int y,int v)
{
	x=find(x);y=find(y);
	if(x==y) return ;
	int sx=ask[x].size(),sy=ask[y].size();
	if(sx>sy) fa[y]=x,link(x,y,v);
	else fa[x]=y,link(y,x,v);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].fr,&a[i].to,&a[i].val);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ask[u].insert(i);ask[v].insert(i);
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) merge(a[i].fr,a[i].to,a[i].val);
	for(int i=1;i<=q;i++) 
	{
		if(ans[i]!=0) printf("%d\n",ans[i]);
		else printf("-1\n");
	}
	return 0;
}
