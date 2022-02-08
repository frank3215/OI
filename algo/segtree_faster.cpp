#include <cstdio>
#include <cmath>
#define sum(i) tree[i].sum
#define tag(i) tree[i].tag
#define d tree[t]
int n,a[100010],m,x,l,r;
struct node{
	int l, r, tag;
	long long sum;
}tree[400010];
void build(int l,int r,int t) 
{
	d.l=l, d.r=r, d.tag=0;
	if(l==r){
		d.sum=a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(l, mid, t<<1);
	build(mid+1, r, t<<1|1);
	d.sum = sum(t<<1) + sum(t<<1|1);
}
void push(int t){
	if(d.l==d.r){
		d.sum=floor(sqrt(d.sum));
		d.tag=(d.sum<=1);
	}
}
long long query(int l,int r,int t)
{
	if(l<=d.l&&d.r<=r) return d.sum;
	int mid = (d.l+d.r)>>1;
	long long ans = 0;
	if(l<=mid) ans += query(l, r, t<<1);
	if(r>mid) ans += query(l, r, t<<1|1);
	return ans;
}
void update(int l,int r,int t)
{
	if(d.tag) return;
	if(d.l==d.r){
		push(t);
		return;
	}
	int mid = (d.l+d.r)>>1;
	if(l<=mid) update(l,r,t<<1);
	if(r>mid) update(l,r,t<<1|1);
	d.sum=sum(t<<1)+sum(t<<1|1);
	d.tag=tag(t<<1)&tag(t<<1|1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n,1);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&x,&l,&r);
		//printf("%lld %lld %lld %lld\n",sum(4),sum(5),sum(6),sum(7));
		if(x==1) printf("%lld\n",query(l,r,1));
		else update(l,r,1);
	}
}
