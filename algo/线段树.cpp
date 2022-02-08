#include <cstdio>
#define maxn 10000
int tree[4*maxn],tval[4*maxn],val[maxn],n,q,l,r,v;
void init(int l,int r,int i){
	if(l==r){
		tval[i]=val[l];
	}else{
		int m=(l+r)/2;
		int a=init(l,m,i*2),b=init(m+1,r,i*2+1);
		tval[i]=a+b;
	}
	return tree[i];
}
int sum(int l,int r,int i,int b,int e){
	if(l>e||r<b) return 0;
	if(b>=l&&e<=r) return tval[i]+tree[i]*(r-l+1);
	int p1,p2,m=(l+r/2);
	p1=find(l,m,i*2,b,e);p2=find(m+1,r,i*2+1,b,e);
	return p1+p2;
}
void add(int l,int r,int i,int b,int e,int v){
	if(l>e||r<b) return;
	if(b>=l&&e<=r){
		tree[]
	}
}
int main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&val[i]);
	init(0,n-1,1);
	for(int i=0;i<1;i++){
		scanf("%d%d%d",&l,&r,&v);
		add(0,n-1,1,l,r,v);
	}
}