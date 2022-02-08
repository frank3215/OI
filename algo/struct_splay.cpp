#include <cstdio>
#include <algorithm>
const int maxn=1e5+10;
char s[3];
int n,mn,m,ans=0,a[maxn],l,r,tot=0;
struct splay_tree{
	int size[maxn],cnt[maxn],ch[maxn][2],fa[maxn],key[maxn],tot,rt,siz,tag[maxn];
	bool get(int x){return x==ch[fa[x]][1];}
	void connect(int x,int f,int w){if((fa[x]=f)) ch[f][w]=x;}
	void pushup(int x){size[x] = cnt[x] + size[ch[x][0]] + size[ch[x][1]]; }
	void pushdown(int x){
		if(x&&tag[x]){
			for(int i=0;i<2;i++)
				if(ch[x][i])
					tag[ch[x][i]]^=tag[x];
			std::swap(ch[x][0],ch[x][1]);
			tag[x]=0;
		}
	}
	int build(int l,int r,int *a,int f=0){ //a为unique sorted sequence
		if(l>r) return 0;

		int mid=(l+r)>>1,u=++tot;
		key[u]=a[mid];
		cnt[u]=size[u]=1;
		if(!(fa[u]=f)) rt=u;
		if(l==r) return u;

		ch[u][0]=build(l,mid-1,a,u);
		ch[u][1]=build(mid+1,r,a,u);
		pushup(u);
		return u;
	}
	void rotate(int x)
	{
		pushdown(fa[x]),pushdown(x);
		int f=fa[x],w=get(x);
		connect(ch[x][w^1],f,w);
		connect(x,fa[f],get(f));
		connect(f,x,w^1);
		pushup(f),pushup(x);
	}
	void splay(int x,int to=0)
	{
		for(int f;(f=fa[x])!=to;rotate(x))
			if(fa[f]!=to)
				rotate( (get(x)==get(f))?f:x );
		if(!to) rt=x;
	}
	void insert(int x)
	{
		int u=rt,f=0;
		while(u&&x!=key[u])
			pushdown(u),f=u,u=ch[u][x>key[u]];
		if(!u){
			u=++tot,size[u]=1,fa[u]=f,key[u]=x;
			if(f) ch[f][x>key[f]]=u;
		}
		if(!rt) rt=u;
		cnt[u]++,splay(u);
	}
	int kth(int x,int u){
		if(!u) return 0;
		pushdown(u);
		int s=size[ch[u][0]];
		if(x<=s) return kth(x,ch[u][0]);
		else if(x<=s+cnt[u]) return u;
		else return kth(x-s-cnt[u],ch[u][1]);
	}
	void delside(int x,int sd)
	{
		insert(mn);
		siz+=size[ch[rt][sd]];
		if(--cnt[rt]) ch[rt][sd]=0;
		else fa[rt=ch[rt][sd^1]]=0;
		pushup(rt);
	}
	void mid(int u,int &cur){
		if(!u) return;
		pushdown(u);
		//printf("%d(%d):%d,%d\n",key[u],u,key[ch[u][0]],key[ch[u][1]]);
		mid(ch[u][0],cur);
		for(int i=0;i<cnt[u];i++)
			a[cur++]=key[u];
		mid(ch[u][1],cur);
	}
	void modify(int l,int r){
		splay(l=kth(l,rt));
		splay(r=kth(r+2,rt),rt);
		tag[ch[r][0]]^=1;
	}
}t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)
		a[i]=i;
	t.build(0,n+1,a);
	while(m--){
		scanf("%d %d",&l,&r);
		t.modify(l,r);
	}
	t.mid(t.rt,tot=0);
	for(int i=0;i<tot;i++)
		if(0<a[i]&&a[i]<=n)
			printf("%d ",a[i]);
}
