#include <cstdio>
const int maxn=1000000,inf=1e9+1;
struct node{
	int g,v,s[2];
	void init(int L,int R){
		g=v=s[0]=s[1]=0;
	}
};
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
