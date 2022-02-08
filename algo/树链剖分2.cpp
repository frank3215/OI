#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int mm=100010;
const int init[2]={0,-3e4};
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline int fun(int i,int x,int y){return i?max(x,y):x+y;}
int n,q,x,y,u,v,
	d[mm],f[mm],a[mm],b[mm],top[mm],size[mm]={},son[mm]={},id[mm]={},
	val[2][3*mm],
	head[mm]={},to[mm],nex[mm],tot=0;
void dfs1(int u,int fa,int dep)
{
	f[u]=fa,
	d[u]=dep,
	size[u]=1;
	//cout<<u<<':'<<fa<<'('<<dep<<')'<<endl;
	for(int i=head[u],v; i; i=nex[i]){
		v=to[i];
		if(size[v]) continue;//Possible to cause errors
		dfs1(v,u,dep+1);
		size[u]+=size[v];
		if(size[v]>size[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int t)
{
	id[u]=++tot;
	cout<<u<<"  "<<tot<<' '<<d[u]<<endl;
	b[tot]=a[u];
	top[u]=t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=head[u]; i; i=nex[i])
		if(!id[to[i]]) dfs2(to[i],to[i]);
}
void push_up(int x){
	val[0][x]=val[0][ls(x)]+val[0][rs(x)];
	val[1][x]=max(val[1][ls(x)],val[1][rs(x)]);
}
void build(int x,const int &l,int &r)
{
	if(l==r)
		val[0][x]=val[1][x]=b[l];
	else{
		int mid=(l+r)>>1;
		build(ls(x),l,mid);
		build(rs(x),mid+1,r);
		push_up(x);
	}
}
int query(int i,int x, int &l, int &r, const int &ml, int &mr)
{
	cout<<l<<' '<<r<<endl;
	if(l<=ml&&mr<=r)
		return val[i][x];
	int mid=(ml+mr)>>1,res=init[i];
	if(l<=mid) res=fun(i,res,query(i,ls(x),l,r,ml,mid));
	if(r>mid) res=fun(i,res,query(i,rs(x),l,r,mid+1,mr));
	return res;
}
void update(int x,int &u, const int &ml, int &mr, int &k)
{
	if(ml==mr) {
		val[0][x]=val[1][x]=k;
		return;
	}
	int mid=(ml+mr)>>1;
	if(id[u]<=mid) update(ls(x),u,ml,mid,k);
	if(id[u]>mid) update(rs(x),u,mid+1,mr,k);
	push_up(x);
}
int range(int i,int x,int y){
	int ans=init[i];
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]])swap(x,y);
		ans=fun(i,ans,query(i,1,id[top[x]],id[x],1,n));
		x=f[top[x]];
	}
	if(d[x]>d[y])swap(x,y);
	ans=fun(i,ans,query(i,1,id[x],id[y],1,n));
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		to[++tot]=y;
		nex[tot]=head[x];
		head[x]=tot;

		to[++tot]=x;
		nex[tot]=head[y];
		head[y]=tot;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs1(1,0,1);
	tot=0;
	dfs2(1,1);
	build(1,1,n);
	scanf("%d",&q);
	char s[100];
	while(q--){
		scanf("%s %d %d",s,&u,&v);
		if(s[1]=='H') update(1,u,1,n,v);
		else printf("%d\n",range(s[1]=='M',u,v));
	}
	return 0;
}