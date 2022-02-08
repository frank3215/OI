#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=500010,inf=1e9+1;
int n,a[maxn],tot=0,i,b[maxn],c[maxn],tmp[2][maxn];
long long ans=0;
struct BIT{
	int t[maxn];
	inline int lb(int x){return x&(-x);}
	inline void add(int x){for(;x<=n;x+=lb(x)) t[x]++;}
	inline int sum(int x){int res=0;for(;x;x-=lb(x)) res+=t[x];return res;}
}t;
struct node{
	int g,v;
	node *s[2];
	node *init(){
		g=v=0;
		s[0]=s[1]=NULL;
		return this;
	}
};
//然而这题还可以用动态开点线段树做……
struct DynamicSegmentTree{
	node t[maxn*10];
	int tot,ll,rr;
	void init(int l,int r){
		t[tot=0].init();
		ll=l,rr=r;
	}
	void pushdown(node *p,int l,int r){
		if(l!=r){
			if(!p->s[0]) p->s[0]=t[++tot].init();
			if(!p->s[1]) p->s[1]=t[++tot].init();
			for(int i=0;i<2;i++)
				p->s[i]->g += p->g;
		}
		p->g=0;
	}
	int calc(node *p,int l,int r){
		return p->v+p->g*(r-l+1);
	}
	void pushup(node *p,int l,int r,int m){
		p->v=calc(p->s[0],l,m)+calc(p->s[1],m+1,r);
	}
	void modify(int L,int R,int k,node *p=NULL,int l=0,int r=0){
		if(!p) p=t,l=ll,r=rr;
		if(L<=l&&r<=R){
			p->g+=k;
			return;
		}
		pushdown(p,l,r);
		int m=(l+r)>>1;
		if(L<=m) modify(L,R,k,p->s[0],l,m);
		if(R>m) modify(L,R,k,p->s[1],m+1,r);
		pushup(p,l,r,m);
	}
	int query(int L,int R,node *p=NULL,int l=0,int r=0){
		if(!p) p=t,l=ll,r=rr;
		//printf("(%d,%d)\n",l,r);
		if(L<=l&&r<=R) return calc(p,l,r);
		pushdown(p,l,r);
		int m=(l+r)>>1,res=0;
		if(L<=m) res+=query(L,R,p->s[0],l,m);
		if(R>m) res+=query(L,R,p->s[1],m+1,r);
		return res;
	}
}T;
int cmp(int x,int y){
	return a[x]>a[y];
}
void mergesort(int l,int r,int k){
	if(l==r){
		tmp[k][l]=a[l];
		return;
	}
	int m=(l+r)>>1,*t1=tmp[k],*t2=tmp[k^1];
	mergesort(l,m,k^1);
	mergesort(m+1,r,k^1);
	for(int i=l,s=l,t=m+1;i<=r;i++){
		if(t>r||(s<=m&&t2[s]<=t2[t]))
			t1[i]=t2[s++];
		else{
			ans+=m+1-s;
			t1[i]=t2[t++];
		}
	}
}
int main(){
	scanf("%d",&n);
	T.init(0,inf);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		//b[i]=i;
	}/*
	sort(b,b+n,cmp);
	for(i=0;i<n;i++){
		if(i&&a[b[i]]==a[b[i-1]]) c[b[i]]=c[b[i-1]];
		else c[b[i]]=++tot;
	}
	for(i=0;i<n;i++){
		t.add(c[i]);
		ans+=t.sum(c[i]-1)*/
	for(i=0;i<n;i++){
		T.modify(a[i],a[i],1);
		ans+=T.query(a[i]+1,inf);
	printf("%lld\n",ans);
	}
	//mergesort(0,n-1,0);
}
