#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int n,m,a[N],c=0,b[N],l,r[N];
struct node{
	int l,r,v;
	node(int l=-1,int r=-1,int v=0):l(l),r(r),v(v){}
}t[20*N];
int build(int l,int r){
	int m=(l+r)/2,cc=++c;
	if(l!=r)
	{
		t[cc].l=build(l,m);
		t[cc].r=build(m+1,r);
	}
	return cc;
}
int update(int p,int l,int r,int v){
	int cc=++c,m=(l+r)/2;
	t[cc]=t[p];
	t[cc].v=t[p].v+1;
	if(l!=r){
		if(v<=m) t[cc].l=update(t[p].l,l,m,v);
		else t[cc].r=update(t[p].r,m+1,r,v);
	}
	return cc;
}
void init(){
	r[0]=build(1,n);
	for(int i=1;i<=n;i++){
		int v=lower_bound(b+1,b+l+1,a[i])-b-1;
		r[i]=update(1,1,n,v);
	}
	return;
}
int search(int i,int j,int k){
	return 0;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		a[i]=b[i];
	}
	sort(b+1,b+n+1);
	l=unique(b+1,b+n+1)-b-1;
	init();
	int i,j,k;
	while(m--){
		scanf("%d %d %d",&i,&j,&k);
		printf("%d\n",search(i,j,k));
	}
	return 0;
}
