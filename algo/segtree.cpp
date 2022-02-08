#include <cstdio>
#include <cmath>
#define sum(i) tree[i].sum
#define tag(i) tree[i].tag
#define d tree[t]
int n,a[100010],m,x,l,r,tot=0;
struct node{
	int l, r, tag, ls, rs;
	long long sum;
}tree[400010];
int build(int l,int r,int t) 
{
	tot++;
	int mid = (l+r)>>1;
	d.l=l, d.r=r, d.tag=0;
	if(r-l==1){
		d.ls=d.rs=-1, d.sum=a[l];
		return t;
	}
	d.ls = build(l, mid, tot);
	d.rs = build(mid, r, tot);
	d.sum = sum(d.ls) + sum(d.rs);
	return t;
}
void push(int t){
	if(d.ls==d.rs){
		d.sum=floor(sqrt(d.sum));
		if(d.sum<=1) d.tag=1;
	}
}
long long query(int l,int r,int t)
{
	if(l<=d.l&&d.r<=r) return d.sum;
	int mid = (d.l+d.r)>>1;
	long long ans = 0;
	if(l<mid) ans += query(l, r, d.ls);
	if(r>mid) ans += query(l, r, d.rs);
	return ans;
}
void update(int l,int r,int t)
{
	if(d.ls==d.rs) push(t);
	if(d.ls==d.rs||d.tag) return;

	int mid = (d.l+d.r)>>1;
	if(l<mid) update(l,r,d.ls);
	if(r>mid) update(l,r,d.rs);

	d.sum=sum(d.ls)+sum(d.rs);
	d.tag=tag(d.ls)&tag(d.rs);
}
int main()
{
	scanf("%d",&n);
	fflush(stdout);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n+1,0);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&x,&l,&r);
		if(x==1) printf("%lld\n",query(l,r+1,0));
		else update(l,r+1,0);
	}
}
