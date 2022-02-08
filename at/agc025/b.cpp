#include <cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef long long ll;
ll n,a,b,c,d,f=1,i,x,y,k,m=998244353,ans=0,invf[300010];
ll exgcd(ll &x,ll &y,ll a,ll b,ll c){
	if(b==0){
		if(c%a) return -1;
		y=0,x=c/a;
		return a;
	}
	ll t=y,d=exgcd(y,x,b,a%b,c);
	y-=(a/b)*x;
	return d;
}
ll calc(ll r,ll g,ll b){
	return f*invf[r]%m*invf[g]%m*invf[b]%m*invf[n-r-g-b]%m;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	d = exgcd(x,y,a,b,c);
//printf("%lld %lld %lld\n",x,y,a*x+b*y);
	while(x<0||y>n)
		x+=d,y-=d;
	while(y<0||x>n)
		x-=d,y+=d;
	while(x>d&&)
//printf("PASS1\n");
	for(i=2;i<=n;i++) f=(f*i)%m;
	exgcd(i,invf[n],m,f,1);
	while(invf[n]<0)
		invf[n]+=m;
	for(i=n-1;i>=0;i--){
		invf[i]=(invf[i+1]*(i+1))%m;
		printf("%lld\n",invf[i]);
	}
	printf("%d\n",max(0,x+y-n));
	for(i=max(0,x+y-n);i<=min(x,y);i++)
		ans=(ans+calc(x-i,i,y-i))%m;
	printf("%lld\n",ans);
}
