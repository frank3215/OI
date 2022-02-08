#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1e5;
int n,a[maxn+10],m,x,l,r,k,tag[4*maxn+10];
long long sum[4*maxn+10];
void build(int l,int r,int c)
{
	tag[c]=0;
	if(l==r){
		sum[c]=a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(l, mid, c<<1);
	build(mid+1, r, c<<1|1);
	sum[c] = sum[c<<1] + sum[c<<1|1];
}
void push(int c,int ll,int lr){
	//printf(" %d(%d) %d %d\n",c,tag[c],tag[c<<1],tag[c<<1|1]);
	tag[c<<1] += tag[c];
	tag[c<<1|1] += tag[c];
	sum[c<<1] += tag[c]*ll;
	sum[c<<1|1] += tag[c]*lr;
	//printf(" %d(%d) %d %d\n",c,tag[c],tag[c<<1],tag[c<<1|1]);
	tag[c]=0;
}
long long query(int L,int R,int c,int l,int r)
{
	//printf("{%d~%d:%d (%d/%lld)\n",l,r,c,tag[c],sum[c]);
	//fflush(stdout);
	if( L<=l && r<=R ) return sum[c];
	int mid = (l+r)>>1;
	long long ans = 0;
	push(c, mid-l+1, r-mid);
	if(L<=mid) ans += query(L, R, c<<1, l, mid);
	if(R>mid) ans += query(L, R, c<<1|1, mid+1, r);
	//printf(">> %lld\n",ans);
	//printf("%d~%d:%d %lld(%d)}\n",l,r,c,sum[c],tag[c]);
	return ans;
}
void update(int L,int R,int c,int l,int r)
{
	if( L<=l && r<=R ) {
		tag[c]+=k;
		sum[c]+=(r-l+1)*k;
		//printf("[%d,%d]%d(%d/%lld)\n",l,r,c,tag[c],sum[c]);
		return;
	}
	int mid = (l+r)>>1;
	push(c, mid-l+1, r-mid);
	if(L<=mid) update(L,R,c<<1,l,mid);
	if(R>mid) update(L,R,c<<1|1,mid+1,r);
	sum[c]=sum[c<<1]+sum[c<<1|1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	while(m--){
		scanf("%d%d%d",&x,&l,&r);
		//printf("%d\t%d\n",m,tag[2]);
		//cout<<m<<endl;
		if(x==2)
			printf("%lld\n",query(l,r,1,1,n));
		else{
			scanf("%d",&k);
			update(l,r,1,1,n);
		}
	}
}
