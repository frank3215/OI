#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+5,maxm=800000+5,maxc=27,maxq=500000+5;
int n,q,las=1,tot=1,tim=0;
int ed[maxn],pos[maxn];
int link[maxm],len[maxm],trans[maxm][maxc];
vector<int> edge[maxm];
int dfn[maxm],to[maxm],sum[maxm*4];
char ch[maxn];
struct node
{
	int x,k,typ,num;
	bool operator < (const node &p) const
	{return x<p.x;}
}a[maxq*2];
int ans[maxq];
void extend(int c)
{
	int cur=++tot,u=las;
	len[cur]=len[las]+1;
	while(u&&!trans[u][c]) trans[u][c]=cur,u=link[u];
	if(!u) link[cur]=1;
	else
	{
		int v=trans[u][c];
		if(len[v]==len[u]+1) link[cur]=v;
		else
		{
			int clone=++tot;
			link[clone]=link[v];
			link[v]=link[cur]=clone;
			len[clone]=len[u]+1;
			for(int i=0;i<maxc;i++) trans[clone][i]=trans[v][i];
			while(u&&trans[u][c]==v) trans[u][c]=clone,u=link[u];
		}
	}
	las=cur;
}
void dfs(int u)
{
	dfn[u]=++tim;
	int sz=edge[u].size();
	for(int i=0;i<sz;i++) dfs(edge[u][i]);
	to[u]=tim;
}
void add(int x,int l,int r,int w)
{
	if(l==r) {++sum[x];return ;}
	int mid=(l+r)/2;
	if(w<=mid) add(x*2,l,mid,w);
	else add(x*2+1,mid+1,r,w);
	sum[x]=sum[x*2]+sum[x*2+1];
}
int query(int x,int l,int r,int ql,int qr)
{
	if(ql>r||l>qr) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return query(x*2,l,mid,ql,qr)+query(x*2+1,mid+1,r,ql,qr);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+ed[i-1]);
		ed[i]=ed[i-1]+strlen(ch+ed[i-1]);
		for(int j=ed[i-1];j<ed[i];j++) extend(ch[j]-'a');
		extend('z'-'a'+1);
	}
	for(int i=1;i<=n;i++)
	{
		pos[i]=1;
		for(int j=ed[i-1];j<ed[i];j++) 
			pos[i]=trans[pos[i]][ch[j]-'a'];
	}
	for(int i=1;i<=tot;i++) edge[link[i]].push_back(i);
//	dfs(1);
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		a[2*i-1]=(node){l-1,k,-1,i};
		a[2*i]=(node){r,k,1,i};
	}
	sort(a+1,a+2*q+1);
	return 0;
	for(int i=1;i<=2*q;i++)
	{
		for(int j=a[i-1].x+1;j<=a[i].x;j++)
		{
			int u=1;
			for(int k=ed[j-1];k<ed[j];k++) u=trans[u][ch[k]-'a'],add(1,1,tot,dfn[u]);
		}
		ans[a[i].num]+=a[i].typ*query(1,1,tot,dfn[pos[a[i].k]],to[pos[a[i].k]]);
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
