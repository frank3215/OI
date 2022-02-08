//BUGS!!!

#include <cstdio>
#include <iostream>
using namespace std;
const int mm=100010;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
int n,m,x,y,z,
	d[mm],f[mm],a[mm],b[mm],top[mm],size[mm]={},son[mm]={},id[mm]={},
	val[3*mm],tag[3*mm],at[mm],lc[3*mm],rc[3*mm],
	head[mm]={},to[mm],nex[mm],tot=0;
char cmd[3];
inline int same(int x){return (rc[ls(x)]==lc[rs(x)]);}
inline void push_up(int x){
	lc[x]=lc[ls(x)],rc[x]=rc[rs(x)],
	val[x] = val[ls(x)]+val[rs(x)]-same(x);
}
void build(int x,int l,int r)
{
	tag[x]=-1;
	if(l==r){
		val[x]=1;
		lc[x]=rc[x]=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	push_up(x);
}
void push_down(int x, int l, int r)
{
	if(tag[x]==-1||l==r){
		tag[x]=-1;
		return;
	}
	tag[ls(x)]=tag[rs(x)]=
	lc[ls(x)]=lc[rs(x)]=rc[ls(x)]=rc[rs(x)]=tag[x],
	val[ls(x)]=val[rs(x)]=1;/*same[x]*/
	tag[x]=-1;
}
int query(int x, int L, int R, int l, int r)
{
	if((L<=l&&r<=R)||tag[x]!=-1/*May cause errors*/)
		return val[x];
	push_down(x,l,r);
	int mid=(l+r)>>1,res=0;
	if(L<=mid) res+=query(ls(x),L,R,l,mid);
	if(R>mid) res+=query(rs(x),L,R,mid+1,r);
	//printf("Q %d~%d %d\n",l,r,res-(l<=mid&&r>mid?same(x):0));
	return res-(L<=mid&&R>mid?same(x):0);
}

void update(int x, int L, int R, int k, int l, int r)
{
	//printf("C %d~%d %d~%d\n",l,r,ml,mr);
	if(L<=l&&r<=R) {
		val[x]=1;
		lc[x]=rc[x]=tag[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	push_down(x,l,r);
	if(L<=mid) update(ls(x),L,R,k,l,mid);
	if(R>mid) update(rs(x),L,R,k,mid+1,r);
	push_up(x);
}
int col(int id,int l,int r,int x){
	if(l==r||tag[x]!=-1) return lc[x];
	int mid=(l+r)>>1;
	if(id<=mid) return col(id,l,mid,ls(x));
	return col(id,mid+1,r,rs(x));
}
void dfs1(int u,int fa,int dep)
{
	f[u]=fa,
	d[u]=dep,
	size[u]=1;
	//printf("%d(%d)\n",u,fa);
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
	b[tot]=a[u];
	top[u]=t;
	//printf("%d:%d\n",u,top[u]);
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=head[u]; i; i=nex[i])
		if(!id[to[i]]) dfs2(to[i],to[i]);
}
void range(int i,int x,int y,int k=0)
{
	int res=0;
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]) swap(x,y);
		if(i) update(1,id[top[x]],id[x],k,1,n);
		else{
			//printf("%d %d %d\n",x,id[x],top[x]);
			res+=query(1,id[top[x]],id[x],1,n);
			//printf("%d %d %d ",id[x],col(id[top[x]],1,n,1),col(id[f[top[x]]],1,n,1));
			res-=( col(id[top[x]],1,n,1) == col(id[f[top[x]]],1,n,1) );
			//printf("%d\n",res);
		}
		x=f[top[x]];
	}
	if(id[x]>id[y]) swap(x,y);
	if(i) update(1,id[x],id[y],k,1,n);
	else printf("%d\n",res+query(1,id[x],id[y],1,n));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		to[++tot]=y;
		nex[tot]=head[x];
		head[x]=tot;

		to[++tot]=x;
		nex[tot]=head[y];
		head[y]=tot;
	}
	dfs1(1,0,1);
	tot=0;
	dfs2(1,1);
	build(1,1,n);
	tot=1e9+10;
	while(m--){
		scanf("%s%d%d",cmd,&x,&y);
		if(cmd[0]=='C')scanf("%d",&z);
		range(cmd[0]=='C',x,y,z);
		//cout<<cmd<<x<<y<<z<<endl;
	}
	return 0;
}